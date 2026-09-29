// ID: 021
// PAPER: P3247R2
// FEATURE: deprecating notion of trivial types
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <type_traits>

struct X
{
    int n;
};

static_assert(std::is_trivial_v<X>);

int main()
{
}
