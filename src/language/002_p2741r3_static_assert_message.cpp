// ID: 002
// PAPER: P2741R3
// FEATURE: user-generated static_assert messages
// GROUP: LANGUAGE
// MIN_GCC: 14
// FEATURE_MACRO: __cpp_static_assert
// FEATURE_MACRO_MIN: 202306L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <cstddef>

struct M
{
    constexpr std::size_t size() const
    {
        return 3;
    }

    constexpr const char* data() const
    {
        return "C26";
    }
};

static_assert(true, M{});

int main()
{
}
