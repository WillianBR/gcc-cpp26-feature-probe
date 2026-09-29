// ID: 020
// PAPER: P3144R2
// FEATURE: deleting pointer to incomplete type is ill-formed
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 
// Positive companion: complete type deletion remains valid.

// Positive companion: complete type deletion remains valid.
struct X
{
    int n;
};

int main()
{
    X* p = new X{26};
    delete p;
}
