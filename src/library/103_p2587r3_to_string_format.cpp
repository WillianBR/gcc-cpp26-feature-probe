// ID: 103
// PAPER: P2587R3
// FEATURE: arithmetic std::to_string changes
// GROUP: LIBRARY
// MIN_GCC: 14
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <string>

int main()
{
    auto s = std::to_string(26);
    return s.empty();
}
