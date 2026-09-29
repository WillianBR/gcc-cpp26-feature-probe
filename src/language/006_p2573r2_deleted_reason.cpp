// ID: 006
// PAPER: P2573R2
// FEATURE: = delete("reason")
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: __cpp_deleted_function
// FEATURE_MACRO_MIN: 202403L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

struct X
{
    void bad() = delete("use good()");

    void good()
    {
    }
};

int main()
{
    X x;
    x.good();
}
