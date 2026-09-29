// ID: 014
// PAPER: P3068R5
// FEATURE: constexpr exceptions
// GROUP: LANGUAGE
// MIN_GCC: 16
// FEATURE_MACRO: __cpp_constexpr_exceptions
// FEATURE_MACRO_MIN: 202411L
// EXPECT_GCC15: UNSUPPORTED
// EXTRA_FLAGS: 

constexpr int f()
{
    try
    {
        throw 26;
    }
    catch (int x)
    {
        return x;
    }
}

static_assert(f() == 26);

int main()
{
}
