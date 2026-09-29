// ID: 012
// PAPER: P2558R2
// FEATURE: @, $, and ` in basic character set
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: -
// FEATURE_MACRO_MIN: -
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#define S2(x) #x
#define S(x) S2(x)

static_assert(
    sizeof(S($)) == 2
    && sizeof(S(@)) == 2
    && sizeof(S(`)) == 2
);

int main()
{
}
