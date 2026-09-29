// ID: 005
// PAPER: P0609R3
// FEATURE: attributes for structured bindings
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: __cpp_structured_bindings
// FEATURE_MACRO_MIN: 202403L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <utility>

int main()
{
    auto [x, y [[maybe_unused]]] = std::pair{26, 13};
    return x == 26 ? 0 : 1;
}
