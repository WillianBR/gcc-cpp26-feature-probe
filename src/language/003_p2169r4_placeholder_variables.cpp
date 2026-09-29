// ID: 003
// PAPER: P2169R4
// FEATURE: placeholder variables with no name
// GROUP: LANGUAGE
// MIN_GCC: 14
// FEATURE_MACRO: __cpp_placeholder_variables
// FEATURE_MACRO_MIN: 202306L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

int main()
{
    auto _ = 1;
    auto _ = 2;
    return 0;
}
