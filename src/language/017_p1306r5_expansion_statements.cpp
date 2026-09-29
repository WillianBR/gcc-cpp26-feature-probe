// ID: 017
// PAPER: P1306R5
// FEATURE: expansion statements
// GROUP: LANGUAGE
// MIN_GCC: 16
// FEATURE_MACRO: __cpp_expansion_statements
// FEATURE_MACRO_MIN: 202506L
// EXPECT_GCC15: UNSUPPORTED
// EXTRA_FLAGS: 

#include <tuple>

int main()
{
    auto t = std::tuple{1, 2};

    template for (auto x : t)
    {
        (void)x;
    }
}
