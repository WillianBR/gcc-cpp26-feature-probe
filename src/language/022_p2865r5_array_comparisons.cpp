// ID: 022
// PAPER: P2865R5
// FEATURE: removing deprecated array comparisons
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 
// Positive companion: pointer comparison after decay is still valid.

// Positive companion: pointer comparison after decay is still valid.
int main()
{
    int a[1]{};
    int b[1]{};

    int* pa = a;
    int* pb = b;

    return pa == pb;
}
