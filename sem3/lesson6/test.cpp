template<unsigned N>
double apply(double (*f)(double), double a)
{
    for(unsigned i = 0; i < N; i++){
    a = f(a);
    }
    return a;
}


#include <cassert>
double sqr(double x) {
    return x * x;
}
int main() {
    assert(1.0 == apply<3>(sqr, 1.0));
    assert(256.0 == apply<3>(sqr, 2.0));
    return 0;
}