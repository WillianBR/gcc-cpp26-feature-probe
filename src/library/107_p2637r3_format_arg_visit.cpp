// ID: 107
// PAPER: P2637R3
// FEATURE: basic_format_arg::visit member
// GROUP: LIBRARY
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <format>
#include <type_traits>

int main()
{
    int value = 26;

    auto store = std::make_format_args(value);
    std::format_args args = store;
    auto a = args.get(0);

    int n = a.visit([](auto x) -> int {
        if constexpr (std::is_same_v<decltype(x), int>)
            return x;
        else
            return -1;
    });

    return n == 26 ? 0 : 1;
}
