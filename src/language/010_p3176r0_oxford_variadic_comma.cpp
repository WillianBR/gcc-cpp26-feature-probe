// ID: 010
// PAPER: P3176R0
// FEATURE: Oxford variadic comma
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <cstdarg>

int count(int first, ...)
{
    return first;
}

int main()
{
    return count(0, 1, 2, 3);
}
