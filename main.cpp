#include <iostream>


template <bool C, typename T = void>
struct enable_if
{
};
template <typename T>
struct enable_if<true, T>
{
    typedef T type;
};


class A
{
    public:
     A() {}
    // explicit A(int) {}

   template <typename T>
    A(T a,  typename enable_if<false>::type * = nullptr ) {}
  
    A(const char*, int = 0) {}
};

int main() {
    A a =  A(1);
    return 0;
}