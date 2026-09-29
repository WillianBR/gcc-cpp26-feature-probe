# C++26 Feature Probe v3.1.1

A practical C++26 conformance/feature probing suite, with Windows `cmd.exe`
as a first-class execution environment.

## English & Português BR

- English version: [README_ENG.md](README_ENG.md)
- Versão em Português: [README.md](README.md)

## GCC 15.3.0 / MinGW-w64 UCRT Baseline Toolchain

The recorded GCC 15.3.0 baseline was produced using the WinLibs build
**MinGW-W64 x86_64-ucrt-posix-seh, r1**, by Brecht Sanders.

Exact download used:

https://github.com/brechtsanders/winlibs_mingw/releases/download/15.3.0posix-14.0.0-ucrt-r1/winlibs-x86_64-posix-seh-gcc-15.3.0-mingw-w64ucrt-14.0.0-r1.zip

Observed fingerprint:

```
GCC:          15.3.0
Target:       x86_64-w64-mingw32
Runtime:      UCRT / POSIX / SEH
Default C++:  __cplusplus = 201703L
C++26:        __cplusplus = 202400L
```

This link identifies the exact binary distribution used to produce the
baseline and makes it possible to repeat the tests using the same toolchain.

## Running the Suite

If `mingwvars.bat` has already been called:

```
mingw32-make
```

Or, to explicitly load the environment:

```
mingw32-make test-mingw ENV_BAT="C:\DESENV\gcc-15.3.0-mingw-w64ucrt-14.0\mingw64\mingwvars.bat"
```

## V3 Philosophy

Each probe is independent. A failed test does not terminate the suite.

Compilation and execution results are kept separate from the expected
results for GCC 15.

Cases that depend on the platform or toolchain configuration may be marked
as `OBSERVE`, preventing a configuration limitation from being incorrectly
classified as the compiler lacking support for a feature.

The suite also generates `feature-macros.txt`, containing the SD-6
`__cpp_*` feature-test macros.

## Corrections Since V2

* P2169R4: two `_` variables are declared, but neither is referenced afterward.
* P0609R3: the attribute is correctly placed after the identifier.
* P3176R0: the probe was rewritten to use the syntax with a comma before `...`.
* P1967R14: the `#embed` resource is kept alongside the source file for deterministic lookup.
* P3074R7: uses `__cpp_trivial_union`.
* P2637R3/basic_format_arg: `make_format_args` receives an lvalue.
* `std::text_encoding` is observational because support may depend on the platform/toolchain configuration.
* Toolchain fingerprinting does not use fragile nested pipelines under `cmd.exe`.

## Generated Files

```
report.txt
feature-macros.txt
logs\*.log
bin\*.exe
```

## Terminology

In the Portuguese documentation, the suite prefers **obsoleto** or
**preterido**.

`deprecated` is preserved only when it refers literally to C/C++ or compiler
terminology, attributes, or diagnostics.

## References

GCC C++ Standards Support:

https://gcc.gnu.org/projects/cxx-status.html

libstdc++ documentation:

https://gcc.gnu.org/onlinedocs/libstdc++/

## V3.1

Corrections made after actual execution with GCC 15.3/MinGW-w64:

* fixes the `cmd.exe` metadata parser (`FOR /F tokens=1,*`), which caused
  all expectations to appear as `UNKNOWN`;
* fixes P2637R3/basic_format_arg by converting the `_Arg_store` returned by
  `make_format_args` to `std::format_args` before calling `get(0)`;
* keeps P1885R12/text_encoding as `OBSERVE`, because the tested MinGW build
  does not define `__cpp_lib_text_encoding`.

## V3.1.1

Editorial changes only, with no intentional changes to probe logic:

* C++ source files were reformatted for human readability;
* the README now documents the exact WinLibs package used for the GCC 15.3.0 baseline;
* test logic, flags, expectations, and metadata remain unchanged from V3.1.
