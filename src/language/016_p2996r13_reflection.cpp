// ID: 016
// PAPER: P2996R13
// FEATURE: reflection
// GROUP: LANGUAGE
// MIN_GCC: 16
// FEATURE_MACRO: __cpp_impl_reflection
// FEATURE_MACRO_MIN: 202506L
// EXPECT_GCC15: UNSUPPORTED
// EXTRA_FLAGS: -freflection

#include <meta>

struct X
{
    int n;
};

constexpr std::meta::info i = ^^X;

int main()
{
}
