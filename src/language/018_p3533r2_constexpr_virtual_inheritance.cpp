// ID: 018
// PAPER: P3533R2
// FEATURE: constexpr virtual inheritance
// GROUP: LANGUAGE
// MIN_GCC: 16
// FEATURE_MACRO: __cpp_constexpr_virtual_inheritance
// FEATURE_MACRO_MIN: 202506L
// EXPECT_GCC15: UNSUPPORTED
// EXTRA_FLAGS: 

struct A
{
    int n = 26;
};

struct B : virtual A
{
    constexpr int f() const
    {
        return n;
    }
};

constexpr int g()
{
    B b;
    return b.f();
}

static_assert(g() == 26);

int main()
{
}
