// ID: 004
// PAPER: P2662R3
// FEATURE: pack indexing
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: __cpp_pack_indexing
// FEATURE_MACRO_MIN: 202311L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <type_traits>

template<class... T>
using first = T...[0];

static_assert(std::is_same_v<first<int, double>, int>);

int main()
{
}
