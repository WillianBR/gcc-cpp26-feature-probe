# C++26 Feature Probe — References

This document provides traceability between the source probes in
`gcc-cpp26-feature-probe` and the WG21 papers that introduced or modified
the C++26 features being tested.

The relationship is:

**WG21 paper → C++26 feature → probe → behavior actually tested**

A successful probe demonstrates that the particular behavior exercised by
that probe is accepted by the tested GCC/libstdc++ toolchain. It does **not**
claim complete conformance with every normative requirement introduced by
the corresponding WG21 paper.

Primary source:

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/

---

# Language Features

## P2738R1 — constexpr cast from void*

**Probe**

`001_p2738r1_constexpr_void_ptr.cpp`

**What is tested**

Tests whether a pointer converted to `void*` can be converted back to its
original pointer type during constant evaluation under the conditions
permitted by C++26.

**Feature-test macro**

`__cpp_constexpr >= 202306L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/p2738r1.pdf

---

## P2741R3 — user-generated static_assert messages

**Probe**

`002_p2741r3_static_assert_message.cpp`

**What is tested**

Tests C++26 support for a `static_assert` diagnostic message produced from
a constant expression rather than being restricted to a string literal.

**Feature-test macro**

`__cpp_static_assert >= 202306L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/p2741r3.pdf

---

## P2169R4 — A nice placeholder with no name

**Probe**

`003_p2169r4_placeholder_variables.cpp`

**What is tested**

Tests repeated declarations using `_` as a placeholder variable name.

The probe intentionally does not reference either placeholder after the
declarations, because referring to `_` when multiple placeholder variables
exist would be ambiguous and would test a different language rule.

**Feature-test macro**

`__cpp_placeholder_variables >= 202306L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/p2169r4.pdf

---

## P2662R3 — Pack Indexing

**Probe**

`004_p2662r3_pack_indexing.cpp`

**What is tested**

Tests C++26 pack-indexing syntax and the ability to select an element from
a parameter pack by index.

**Feature-test macro**

`__cpp_pack_indexing >= 202311L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/p2662r3.pdf

---

## P0609R3 — Attributes for Structured Bindings

**Probe**

`005_p0609r3_structured_binding_attributes.cpp`

**What is tested**

Tests the C++26 ability to apply an attribute to an individual identifier
inside a structured binding declaration.

**Feature-test macro**

`__cpp_structured_bindings >= 202403L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p0609r3.pdf

---

## P2573R2 — = delete("should have a reason");

**Probe**

`006_p2573r2_deleted_reason.cpp`

**What is tested**

Tests the C++26 syntax that permits a deleted function declaration to carry
a textual reason.

**Feature-test macro**

`__cpp_deleted_function >= 202403L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p2573r2.html

---

## P2893R3 — Variadic Friends

**Probe**

`007_p2893r3_variadic_friends.cpp`

**What is tested**

Tests the C++26 variadic friend declaration facility.

**Feature-test macro**

`__cpp_variadic_friend >= 202403L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p2893r3.html

---

## P2747R2 — constexpr placement new

**Probe**

`008_p2747r2_constexpr_placement_new.cpp`

**What is tested**

Tests placement `new` during constant evaluation in a context permitted by
the C++26 rules.

**Feature-test macro**

`__cpp_constexpr >= 202406L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p2747r2.html

---

## P0963R3 — Structured binding declaration as a condition

**Probe**

`009_p0963r3_structured_binding_condition.cpp`

**What is tested**

Tests the C++26 ability to use a structured binding declaration directly
as a condition.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p0963r3.html

---

## P3176R0 — The Oxford variadic comma

**Probe**

`010_p3176r0_oxford_variadic_comma.cpp`

**What is tested**

Tests the C++26 variadic-function syntax in which a comma appears before
the ellipsis.

The probe deliberately uses the new syntax rather than relying on the
older omitted-comma form.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p3176r0.html

---

## P1967R14 — #embed

**Probe**

`011_p1967r14_embed.cpp`

**What is tested**

Tests the C++26 `#embed` preprocessing directive by embedding the contents
of a binary resource into the translation unit.

The resource file is stored alongside the probe source to make lookup
deterministic.

**Feature-test macro**

`__cpp_pp_embed >= 202502L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p1967r14.html

---

## P2558R2 — Add @, $, and ` to the basic character set

**Probe**

`012_p2558r2_basic_charset.cpp`

**What is tested**

Tests source-code handling of characters added to the C++ basic character
set by the proposal.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2558r2.html

---

## P1061R10 — Structured Binding Packs

**Probe**

`013_p1061r10_structured_binding_pack.cpp`

**What is tested**

Tests C++26 structured-binding pack syntax.

**Feature-test macro**

`__cpp_structured_bindings >= 202411L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p1061r10.html

---

## P3068R5 — Allowing exception throwing in constant-evaluation

**Probe**

`014_p3068r5_constexpr_exceptions.cpp`

**What is tested**

Tests exception handling during constant evaluation as permitted by C++26.

**Feature-test macro**

`__cpp_constexpr_exceptions >= 202411L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p3068r5.html

---

## P2900R14 — Contracts for C++

**Probe**

`015_p2900r14_contracts.cpp`

**What is tested**

Tests syntax from the C++26 Contracts facility.

Compiler-specific options may be necessary when a GCC release provides
Contracts as an opt-in implementation.

The probe should therefore be interpreted together with the compiler flags
recorded by the test suite.

**Feature-test macro**

`__cpp_contracts >= 202502L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p2900r14.pdf

---

## P2996R13 — Reflection for C++26

**Probe**

`016_p2996r13_reflection.cpp`

**What is tested**

Tests C++26 static-reflection syntax supported by GCC, including the
reflection operator used by the probe.

For the tested GCC implementation, reflection is enabled explicitly with:

`-freflection`

**Feature-test macro**

`__cpp_impl_reflection >= 202506L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p2996r13.html

---

## P1306R5 — Expansion Statements

**Probe**

`017_p1306r5_expansion_statements.cpp`

**What is tested**

Tests the C++26 expansion-statement facility, including the `template for`
syntax exercised by the probe.

**Feature-test macro**

`__cpp_expansion_statements >= 202506L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p1306r5.html

---

## P3533R2 — constexpr virtual inheritance

**Probe**

`018_p3533r2_constexpr_virtual_inheritance.cpp`

**What is tested**

Tests constant evaluation involving virtual inheritance as permitted by
the C++26 changes.

**Feature-test macro**

`__cpp_constexpr_virtual_inheritance >= 202506L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p3533r2.html

---

## P3074R7 — trivial unions (was std::uninitialized<T>)

**Probe**

`019_p3074r7_trivial_unions.cpp`

**What is tested**

Tests the C++26 language changes concerning trivial unions.

This probe uses the dedicated feature-test macro rather than attempting to
infer support from older union behavior that could produce a false positive.

**Feature-test macro**

`__cpp_trivial_union >= 202502L`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p3074r7.html

---

## P3144R2 — Deleting a pointer to an incomplete type should be ill-formed

**Probe**

`020_p3144r2_delete_incomplete.cpp`

**What is tested**

This is a positive companion probe associated with the C++26 change to
deleting pointers to incomplete types.

It verifies valid behavior surrounding the changed rule.

A successful result must **not** be interpreted as a complete test of every
ill-formed case introduced by P3144R2.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p3144r2.pdf

---

## P3247R2 — Deprecate the notion of trivial types

**Probe**

`021_p3247r2_trivial_types.cpp`

**What is tested**

This is a positive probe associated with the C++26 changes surrounding the
notion of trivial types.

The probe exercises behavior that remains valid after the changes.

A successful result does **not** imply that every deprecation or library
change specified by P3247R2 has been diagnosed or implemented.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p3247r2.html

---

## P2865R5 — Remove deprecated array comparisons from C++26

**Probe**

`022_p2865r5_array_comparisons.cpp`

**What is tested**

This is a positive companion probe associated with the removal of deprecated
array-comparison behavior.

It verifies valid comparison behavior around the affected language rules.

A successful result is deliberately narrower than claiming complete
implementation of every removal specified by P2865R5.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p2865r5.pdf

---

# Standard Library Features

## P2497R0 — Testing for success or failure of <charconv> functions

**Probe**

`101_p2497r0_charconv_result_bool.cpp`

**What is tested**

Tests the C++26 boolean interface for determining whether a `<charconv>`
conversion result represents success or failure.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2497r0.html

---

## P1885R12 — Naming Text Encodings to Demystify Them

**Probe**

`102_p1885r12_text_encoding.cpp`

**What is tested**

Tests availability of the C++26 `std::text_encoding` standard-library
facility in the tested libstdc++ configuration.

This probe is classified as `OBSERVE` because availability can depend on
the standard-library build, target, or platform configuration.

**Feature-test macro**

`__cpp_lib_text_encoding`

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p1885r12.pdf

---

## P2587R3 — to_string or not to_string

**Probe**

`103_p2587r3_to_string_format.cpp`

**What is tested**

Tests the C++26 behavior of the `std::to_string` family after its
integration with the standard formatting machinery.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/p2587r3.html

---

## P2510R3 — Formatting pointers

**Probe**

`104_p2510r3_format_pointer.cpp`

**What is tested**

Tests formatting pointer values using the standard formatting library.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2510r3.pdf

---

## P2562R1 — constexpr Stable Sorting

**Probe**

`105_p2562r1_constexpr_stable_sort.cpp`

**What is tested**

Tests whether `std::stable_sort` can be used during constant evaluation as
specified for C++26.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2562r1.html

---

## P2637R3 — Member visit

**Probes**

`106_p2637r3_variant_member_visit.cpp`

`107_p2637r3_format_arg_visit.cpp`

**What is tested**

The paper affects more than one visitation facility, so this project uses
two independent probes.

Probe 106 exercises member `visit` functionality associated with
`std::variant`.

Probe 107 exercises visitation through `std::basic_format_arg`.

For probe 107, the argument store produced by `std::make_format_args` is
converted to `std::format_args` before retrieving the argument with
`get(0)`.

The existence of two probes for one paper is intentional: a successful
result for one facility must not silently imply that the other facility
works.

**Official WG21 paper**

https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/p2637r3.html

---

# Implementation and SD-6 Probes

These probes do not map one-to-one to a single C++26 WG21 proposal.

They inspect implementation information used to characterize the tested
toolchain.

## 201 — __cplusplus

**Probe**

`201_sd6_cplusplus.cpp`

**What is tested**

Checks the value of the standard `__cplusplus` predefined macro while the
probe is compiled in C++26 mode.

This provides evidence about the language mode selected by the compiler; it
does not by itself demonstrate support for individual C++26 features.

---

## 202 — GNU libstdc++ version information

**Probe**

`202_gnu_libstdcxx_version.cpp`

**What is tested**

Examines GNU libstdc++ implementation version information used to identify
the standard-library implementation accompanying the tested compiler.

These are implementation-identification probes rather than C++26 language
feature probes.

---

# Interpretation

The project deliberately distinguishes between:

**Paper**

The WG21 proposal and its normative changes.

**Feature**

The language or library capability introduced or modified by that paper.

**Probe**

A small program exercising a specific observable part of that capability.

**Result**

Whether that particular program compiled and, when applicable, executed
successfully with the tested GCC/libstdc++ toolchain.

Therefore:

> `SUPPORTED` means that the behavior exercised by the probe is supported.

It does **not** mean:

> every normative requirement contained in the corresponding WG21 paper has
> been exhaustively tested.

This distinction is especially important for large proposals such as
Contracts and Reflection and for the positive companion probes associated
with P3144R2, P3247R2, and P2865R5.

---

# External Reference Tables

The following resources are useful for comparing the experimental results of
this project with published implementation-status information.

## GCC C++ Standards Support

https://gcc.gnu.org/projects/cxx-status.html

## cppreference — C++ compiler support

https://en.cppreference.com/w/cpp/compiler_support.html

## cppreference — C++26 compiler support

https://en.cppreference.com/w/cpp/compiler_support/26.html

These tables are references for comparison.

The actual result recorded by `gcc-cpp26-feature-probe` comes from compiling
and, where applicable, executing the probe against the specified toolchain.
