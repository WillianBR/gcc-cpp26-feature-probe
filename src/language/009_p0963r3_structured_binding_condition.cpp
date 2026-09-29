// ID: 009
// PAPER: P0963R3
// FEATURE: structured binding declaration as condition
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

struct R
{
    int n;
    bool ok;

    explicit operator bool() const
    {
        return ok;
    }
};

int main()
{
    if (auto [n, ok] = R{26, true})
        return n == 26 && ok ? 0 : 1;

    return 2;
}
