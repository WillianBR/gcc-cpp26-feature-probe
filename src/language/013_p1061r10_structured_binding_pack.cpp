// ID: 013
// PAPER: P1061R10
// FEATURE: structured bindings introduce a pack
// GROUP: LANGUAGE
// MIN_GCC: 16
// FEATURE_MACRO: __cpp_structured_bindings
// FEATURE_MACRO_MIN: 202411L
// EXPECT_GCC15: UNSUPPORTED
// EXTRA_FLAGS: 

#include <tuple>

template<class T>
void f(T t)
{
    auto [head, ...tail] = t;
    (void)head;
    (void)sizeof...(tail);
}

int main()
{
    f(std::tuple{1, 2, 3});
}
