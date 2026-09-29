// ID: 007
// PAPER: P2893R3
// FEATURE: variadic friends
// GROUP: LANGUAGE
// MIN_GCC: 15
// FEATURE_MACRO: __cpp_variadic_friend
// FEATURE_MACRO_MIN: 202403L
// EXPECT_GCC15: SUPPORTED
// EXTRA_FLAGS: 

template<class... T>
struct X
{
    friend T...;
};

struct A {};
struct B {};

X<A, B> x;

int main()
{
    (void)x;
}
