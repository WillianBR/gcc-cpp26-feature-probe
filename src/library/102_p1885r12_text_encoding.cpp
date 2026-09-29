// ID: 102
// PAPER: P1885R12
// FEATURE: std::text_encoding
// GROUP: LIBRARY
// MIN_GCC: 14
// FEATURE_MACRO: __cpp_lib_text_encoding
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: OBSERVE
// EXTRA_FLAGS: 

#include <text_encoding>

#ifndef __cpp_lib_text_encoding
#  error "__cpp_lib_text_encoding not defined by this libstdc++ configuration"
#endif

int main()
{
    auto encoding = std::text_encoding::environment();
    (void)encoding;
}
