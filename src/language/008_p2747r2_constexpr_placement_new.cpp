// ID: 008
// PAPER: P2747R2
// FEATURE: constexpr placement new
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: __cpp_constexpr
// FEATURE_MACRO_MIN: 202406L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

#include <memory>

struct X
{
    int n;
};

consteval int f()
{
    std::allocator<X> a;
    X* p = a.allocate(1);

    std::construct_at(p, X{26});
    int result = p->n;

    std::destroy_at(p);
    a.deallocate(p, 1);

    return result;
}

static_assert(f() == 26);

int main()
{
}
