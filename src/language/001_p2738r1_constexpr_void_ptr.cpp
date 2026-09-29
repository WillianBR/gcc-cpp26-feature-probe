// ID: 001
// PAPER: P2738R1
// FEATURE: constexpr cast from void*
// GROUP: LANGUAGE
// MIN_GCC: 14
// FEATURE_MACRO: __cpp_constexpr
// FEATURE_MACRO_MIN: 202306L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

constexpr int f()
{
    int x = 26;
    void* p = &x;
    return *static_cast<int*>(p);
}

static_assert(f() == 26);

int main()
{
}
