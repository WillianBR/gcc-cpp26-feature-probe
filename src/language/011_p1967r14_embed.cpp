// ID: 011
// PAPER: P1967R14
// FEATURE: #embed
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: __cpp_pp_embed
// FEATURE_MACRO_MIN: 202502L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

static const unsigned char b[] = {
#embed "embed.bin"
};

static_assert(sizeof(b) == 4);

int main()
{
    return b[0] == 'C'
        && b[1] == '2'
        && b[2] == '6'
        && b[3] == '!'
        ? 0
        : 1;
}
