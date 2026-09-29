// ID: 015
// PAPER: P2900R14
// FEATURE: contracts
// GROUP: LANGUAGE
// MIN_GCC: 16
// FEATURE_MACRO: __cpp_contracts
// FEATURE_MACRO_MIN: 202502L
// EXPECT_GCC15: UNSUPPORTED
// EXTRA_FLAGS: 

int f(int x)
    pre(x > 0)
    post(r: r > 0)
{
    return x;
}

int main()
{
    return f(1) - 1;
}
