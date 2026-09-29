// ID: 101
// PAPER: P2497R0
// FEATURE: test success/failure of charconv functions
// GROUP: LIBRARY
// MIN_GCC: 14
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <charconv>

int main()
{
    int n{};
    const char* s = "26";

    auto result = std::from_chars(s, s + 2, n);
    return result && n == 26 ? 0 : 1;
}
