// ID: 104
// PAPER: P2510R3
// FEATURE: formatting pointers
// GROUP: LIBRARY
// MIN_GCC: 14
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <format>

int main()
{
    int x = 0;
    auto s = std::format("{}", static_cast<void*>(&x));
    return s.empty();
}
