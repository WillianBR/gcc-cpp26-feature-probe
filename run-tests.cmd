@echo off
setlocal EnableExtensions EnableDelayedExpansion
chcp 65001 >nul

set "CXX=g++"
set "FLAGS=-std=c++26 -Wall -Wextra"
set "ENV_BAT="
set "STRICT=0"

:args
if "%~1"=="" goto args_done
if /I "%~1"=="--env" (set "ENV_BAT=%~2"&shift&shift&goto args)
if /I "%~1"=="--cxx" (set "CXX=%~2"&shift&shift&goto args)
if /I "%~1"=="--flags" (set "FLAGS=%~2"&shift&shift&goto args)
if /I "%~1"=="--strict" (set "STRICT=1"&shift&goto args)
shift
goto args
:args_done

if defined ENV_BAT (
  if not exist "%ENV_BAT%" (
    echo ERROR: environment BAT not found: %ENV_BAT%
    exit /b 2
  )
  call "%ENV_BAT%"
  if errorlevel 1 (
    echo ERROR: environment BAT returned an error.
    exit /b 2
  )
)

if not exist logs mkdir logs
if not exist bin mkdir bin
del /q logs\*.log >nul 2>&1
del /q bin\*.exe >nul 2>&1
del /q report.txt >nul 2>&1
del /q feature-macros.txt >nul 2>&1

>report.txt echo C++26 FEATURE PROBE V3.1
>>report.txt echo ======================
>>report.txt echo.
>>report.txt echo ENV_BAT=%ENV_BAT%
>>report.txt echo CXX=%CXX%
>>report.txt echo FLAGS=%FLAGS%
>>report.txt echo.

echo ============================================================
echo C++26 FEATURE PROBE V3.1 - cmd.exe
echo ============================================================

rem Fingerprint without fragile nested cmd pipes
>>report.txt echo --- TOOLCHAIN FINGERPRINT ---
>>report.txt echo ^> compiler --version
"%CXX%" --version >>report.txt 2>&1
>>report.txt echo ^> compiler -dumpmachine
"%CXX%" -dumpmachine >>report.txt 2>&1
>>report.txt echo ^> compiler -dumpfullversion
"%CXX%" -dumpfullversion >>report.txt 2>&1
>>report.txt echo ^> resolved compiler
for %%I in ("%CXX%") do >>report.txt echo %%~f$PATH:I
>>report.txt echo.

rem Get default and C++26 macro sets into files, then use FINDSTR separately.
>logs\macros-default.txt echo.
"%CXX%" -dM -E -x c++ logs\macros-default.txt >logs\macros-default.out 2>logs\macros-default.err
>>report.txt echo --- DEFAULT __cplusplus ---
findstr /C:"#define __cplusplus" logs\macros-default.out >>report.txt

>logs\macros-cxx26.txt echo.
"%CXX%" -std=c++26 -dM -E -x c++ logs\macros-cxx26.txt >logs\macros-cxx26.out 2>logs\macros-cxx26.err
>>report.txt echo --- C++26 __cplusplus ---
findstr /C:"#define __cplusplus" logs\macros-cxx26.out >>report.txt
>>report.txt echo.

rem Dump feature-test macros from headers
"%CXX%" -std=c++26 -dM -E -x c++ src\macros\all_macros.cpp >feature-macros-all.txt 2>logs\feature-macros.err
findstr /B /C:"#define __cpp_" feature-macros-all.txt >feature-macros.txt
del /q feature-macros-all.txt >nul 2>&1

>>report.txt echo RESULT ^| EXPECTED ^| GROUP ^| TEST
>>report.txt echo -------^|----------^|-------^|--------------------------------------------

set /a TOTAL=0,SUP=0,UNSUP=0,RUNFAIL=0,TESTERR=0,MATCH=0,DIFF=0,OBS=0

for %%D in (language library macros) do (
  echo.
  echo ==================== %%D ====================
  for %%F in (src\%%D\*.cpp) do (
    if /I not "%%~nxF"=="all_macros.cpp" (
      set /a TOTAL+=1
      set "BASE=%%~nF"
      set "EXPECT=UNKNOWN"
      set "EXTRA="
      set "MACRO=-"
      set "MACROMIN=-"
      for /f "tokens=1,* delims=:" %%A in ('findstr /B /C:"// EXPECT_GCC15:" "%%F"') do for /f "tokens=*" %%Z in ("%%B") do set "EXPECT=%%Z"
      for /f "tokens=1,* delims=:" %%A in ('findstr /B /C:"// EXTRA_FLAGS:" "%%F"') do for /f "tokens=*" %%Z in ("%%B") do set "EXTRA=%%Z"
      for /f "tokens=1,* delims=:" %%A in ('findstr /B /C:"// FEATURE_MACRO:" "%%F"') do for /f "tokens=*" %%Z in ("%%B") do set "MACRO=%%Z"
      for /f "tokens=1,* delims=:" %%A in ('findstr /B /C:"// FEATURE_MACRO_MIN:" "%%F"') do for /f "tokens=*" %%Z in ("%%B") do set "MACROMIN=%%Z"

      echo [!TOTAL!] %%~nxF
      echo     expected GCC15: !EXPECT!
      if not "!MACRO!"=="-" echo     macro: !MACRO! ^>= !MACROMIN!

      "%CXX%" %FLAGS% !EXTRA! "%%F" -o "bin\!BASE!.exe" >"logs\!BASE!.log" 2>&1
      if errorlevel 1 (
        set "RESULT=UNSUPPORTED"
        set /a UNSUP+=1
        echo     compile: UNSUPPORTED
      ) else (
        set "RESULT=SUPPORTED"
        set /a SUP+=1
        "bin\!BASE!.exe" >>"logs\!BASE!.log" 2>&1
        if errorlevel 1 (
          set "RESULT=RUNTIME-FAIL"
          set /a RUNFAIL+=1
          echo     runtime: FAIL
        ) else (
          echo     compile/runtime: SUPPORTED
        )
      )

      if /I "!EXPECT!"=="OBSERVE" (
        set "M=OBSERVED"
        set /a OBS+=1
      ) else (
        set "M=DIFF"
        if /I "!EXPECT!"=="!RESULT!" set "M=OK"
        if "!M!"=="OK" (set /a MATCH+=1) else (set /a DIFF+=1)
      )
      >>report.txt echo !RESULT! ^| !EXPECT! ^| %%D ^| %%~nxF [!M!]
    )
  )
)

>>report.txt echo.
>>report.txt echo SUMMARY
>>report.txt echo Total...............: !TOTAL!
>>report.txt echo Supported...........: !SUP!
>>report.txt echo Unsupported.........: !UNSUP!
>>report.txt echo Runtime failures....: !RUNFAIL!
>>report.txt echo Expected matches....: !MATCH!
>>report.txt echo Differences.........: !DIFF!
>>report.txt echo Observational.......: !OBS!

echo.
echo ============================================================
echo Total !TOTAL!  Supported !SUP!  Unsupported !UNSUP!
echo RuntimeFail !RUNFAIL!  Expected matches !MATCH!  Differences !DIFF!
echo Observational !OBS!
echo ============================================================
echo report.txt          - summary
echo feature-macros.txt  - SD-6 macros exposed by compiler/library
echo logs\*.log          - diagnostics per probe
exit /b 0
