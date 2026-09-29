# Manifesto de testes — V3

| ID | Grupo | Paper | Feature | GCC mínimo | Macro SD-6 | Valor mínimo | GCC 15 |
|---:|---|---|---|---:|---|---:|---|
| 001 | language | P2738R1 | constexpr cast from void* | 14 | __cpp_constexpr | 202306L | SUPPORTED |
| 002 | language | P2741R3 | user-generated static_assert messages | 14 | __cpp_static_assert | 202306L | SUPPORTED |
| 003 | language | P2169R4 | placeholder variables with no name | 14 | __cpp_placeholder_variables | 202306L | SUPPORTED |
| 004 | language | P2662R3 | pack indexing | 15 | __cpp_pack_indexing | 202311L | SUPPORTED |
| 005 | language | P0609R3 | attributes for structured bindings | 15 | __cpp_structured_bindings | 202403L | SUPPORTED |
| 006 | language | P2573R2 | = delete("reason") | 15 | __cpp_deleted_function | 202403L | SUPPORTED |
| 007 | language | P2893R3 | variadic friends | 15 | __cpp_variadic_friend | 202403L | SUPPORTED |
| 008 | language | P2747R2 | constexpr placement new | 15 | __cpp_constexpr | 202406L | SUPPORTED |
| 009 | language | P0963R3 | structured binding declaration as condition | 15 | - | - | SUPPORTED |
| 010 | language | P3176R0 | Oxford variadic comma | 15 | - | - | SUPPORTED |
| 011 | language | P1967R14 | #embed | 15 | __cpp_pp_embed | 202502L | SUPPORTED |
| 012 | language | P2558R2 | @, $, and ` in basic character set | 15 | - | - | SUPPORTED |
| 013 | language | P1061R10 | structured bindings introduce a pack | 16 | __cpp_structured_bindings | 202411L | UNSUPPORTED |
| 014 | language | P3068R5 | constexpr exceptions | 16 | __cpp_constexpr_exceptions | 202411L | UNSUPPORTED |
| 015 | language | P2900R14 | contracts | 16 | __cpp_contracts | 202502L | UNSUPPORTED |
| 016 | language | P2996R13 | reflection | 16 | __cpp_impl_reflection | 202506L | UNSUPPORTED |
| 017 | language | P1306R5 | expansion statements | 16 | __cpp_expansion_statements | 202506L | UNSUPPORTED |
| 018 | language | P3533R2 | constexpr virtual inheritance | 16 | __cpp_constexpr_virtual_inheritance | 202506L | UNSUPPORTED |
| 019 | language | P3074R7 | trivial unions | 17 | __cpp_trivial_union | 202502L | UNSUPPORTED |
| 020 | language | P3144R2 | deleting pointer to incomplete type is ill-formed | 15 | - | - | SUPPORTED |
| 021 | language | P3247R2 | deprecating notion of trivial types | 15 | - | - | SUPPORTED |
| 022 | language | P2865R5 | removing deprecated array comparisons | 15 | - | - | SUPPORTED |
| 101 | library | P2497R0 | test success/failure of charconv functions | 14 | - | - | SUPPORTED |
| 102 | library | P1885R12 | std::text_encoding | 14 | __cpp_lib_text_encoding | - | OBSERVE |
| 103 | library | P2587R3 | arithmetic std::to_string changes | 14 | - | - | SUPPORTED |
| 104 | library | P2510R3 | formatting pointers | 14 | - | - | SUPPORTED |
| 105 | library | P2562R1 | constexpr stable sorting | 15 | - | - | SUPPORTED |
| 106 | library | P2637R3 | std::variant::visit member | 15 | - | - | SUPPORTED |
| 107 | library | P2637R3 | basic_format_arg::visit member | 15 | - | - | SUPPORTED |
| 201 | macros | SD6 | __cplusplus in C++26 mode | 14 | - | - | SUPPORTED |
| 202 | macros | GNU | libstdc++ release/date macros | 0 | - | - | SUPPORTED |
