# C++26 Feature Probe v3.1.1

Suíte prática de conformidade/feature probing para C++26, com Windows `cmd.exe`
como ambiente de execução de primeira classe.

## English & Português BR

English version: [README_ENG.md](README_ENG.md)
Versão em Português: [README.md](README.md)

## Toolchain da baseline GCC 15.3.0 / MinGW-w64 UCRT

A baseline registrada para GCC 15.3.0 foi executada com o build WinLibs
**MinGW-W64 x86_64-ucrt-posix-seh, r1**, de Brecht Sanders.

Download exato utilizado:

https://github.com/brechtsanders/winlibs_mingw/releases/download/15.3.0posix-14.0.0-ucrt-r1/winlibs-x86_64-posix-seh-gcc-15.3.0-mingw-w64ucrt-14.0.0-r1.zip

Fingerprint observado:

    GCC:       15.3.0
    Target:    x86_64-w64-mingw32
    Runtime:   UCRT / POSIX / SEH
    C++ padrão: __cplusplus = 201703L
    C++26:      __cplusplus = 202400L

Esse link identifica o binário usado para produzir a baseline e permite
repetir os testes com o mesmo toolchain.

## Execução

Se `mingwvars.bat` já foi chamado:

    mingw32-make

Ou carregando explicitamente o ambiente:

    mingw32-make test-mingw ENV_BAT="C:\DESENV\gcc-15.3.0-mingw-w64ucrt-14.0\mingw64\mingwvars.bat"

## Filosofia da V3

Cada probe é independente. Falhar um teste não encerra a suíte.

Resultados de compilação/execução são separados da expectativa para GCC 15.
Casos dependentes da configuração/plataforma podem ser `OBSERVE`, evitando
classificar uma limitação de configuração como ausência da feature no compilador.

A suíte também gera `feature-macros.txt` com macros SD-6 `__cpp_*`.

## Correções sobre V2

* P2169R4: duas `_` são declaradas, mas nenhuma é referenciada depois.
* P0609R3: atributo corretamente após o identificador.
* P3176R0: teste refeito para a sintaxe com vírgula antes de `...`.
* P1967R14: recurso de `#embed` fica junto ao fonte para busca determinística.
* P3074R7: usa `__cpp_trivial_union`.
* P2637R3/basic_format_arg: `make_format_args` recebe lvalue.
* `std::text_encoding` é observacional por poder depender da configuração/plataforma.
* fingerprint não usa pipelines frágeis aninhados no `cmd.exe`.

## Arquivos gerados

    report.txt
    feature-macros.txt
    logs\*.log
    bin\*.exe

## Terminologia

Em texto português, a suíte prefere **obsoleto** ou **preterido**.
`deprecated` é preservado apenas quando se refere literalmente a terminologia,
atributo ou diagnóstico de C/C++/compilador.

## Referências

GCC C++ Standards Support:
https://gcc.gnu.org/projects/cxx-status.html

libstdc++ documentation:
https://gcc.gnu.org/onlinedocs/libstdc++/

## V3.1

Correções após execução real no GCC 15.3/MinGW-w64:

* corrige parser de metadados do `cmd.exe` (`FOR /F tokens=1,*`), que fazia
  todas as expectativas aparecerem como `UNKNOWN`;
* corrige P2637R3/basic_format_arg: converte o `_Arg_store` retornado por
  `make_format_args` para `std::format_args` antes de chamar `get(0)`;
* mantém P1885R12/text_encoding como `OBSERVE`, pois o build MinGW testado
  não define `__cpp_lib_text_encoding`.

## V3.1.1

Mudança exclusivamente editorial, sem alteração intencional na lógica dos probes:

* fontes C++ reformatados para leitura humana;
* README documenta o pacote WinLibs exato usado na baseline GCC 15.3.0;
* lógica, flags, expectativas e metadados dos testes permanecem os mesmos da V3.1.
