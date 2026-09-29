// ID: 201
// PAPER: SD6
// FEATURE: __cplusplus in C++26 mode
// GROUP: MACROS
// MIN_GCC: 14
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <iostream>

int main()
{
    std::cout << "__cplusplus=" << __cplusplus << "\n";
    return __cplusplus >= 202400L ? 0 : 1;
}
