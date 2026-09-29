// ID: 202
// PAPER: GNU
// FEATURE: libstdc++ release/date macros
// GROUP: MACROS
// MIN_GCC: 0
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <bits/c++config.h>
#include <iostream>

int main()
{
#ifdef _GLIBCXX_RELEASE
    std::cout << "_GLIBCXX_RELEASE=" << _GLIBCXX_RELEASE << "\n";
#endif

#ifdef __GLIBCXX__
    std::cout << "__GLIBCXX__=" << __GLIBCXX__ << "\n";
#endif
}
