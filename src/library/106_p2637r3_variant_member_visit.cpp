// ID: 106
// PAPER: P2637R3
// FEATURE: std::variant::visit member
// GROUP: LIBRARY
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <variant>

int main()
{
    std::variant<int, double> v = 26;

    return v.visit([](auto x) {
        return int(x);
    }) == 26 ? 0 : 1;
}
