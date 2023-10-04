class Base {

private:

    int a;

public:

    Base() { }

    virtual int get() const { return a; }

};



class Derived: public Base {

private:

    int a;

public:

    Derived(int a): a(a) { }

    int get() const { return a; }

};



#include <iostream>

int main() {

    Base b;

    Derived d(2);

    std::cout << b.get() << " " << d.get();

    return 0;

}