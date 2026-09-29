// ID: 105
// PAPER: P2562R1
// FEATURE: constexpr stable sorting
// GROUP: LIBRARY
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <algorithm>
#include <array>

constexpr bool f()
{
    std::array a{3, 1, 2};
    std::stable_sort(a.begin(), a.end());
    return a == std::array{1, 2, 3};
}

static_assert(f());

int main()
{
}
