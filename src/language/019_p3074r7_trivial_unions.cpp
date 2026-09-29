// ID: 019
// PAPER: P3074R7
// FEATURE: trivial unions
// GROUP: LANGUAGE
// MIN_GCC: 17
// FEATURE_MACRO: __cpp_trivial_union
// FEATURE_MACRO_MIN: 202502L
// EXPECT_GCC15: UNSUPPORTED
// EXTRA_FLAGS: 

#ifndef __cpp_trivial_union
#  error "__cpp_trivial_union missing"
#elif __cpp_trivial_union < 202502L
#  error "__cpp_trivial_union too old"
#endif

int main()
{
}
