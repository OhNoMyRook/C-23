#include <iostream>

int foo(){
    return 10;
}

int product(double x, double y, double z=1){
    return x*y*z;
}

int fooo( int &i ){
    i = 100;
}

void fo( std::string );

int main(){
    int a = foo();
    std::cout << a << std::endl;
    int b = product(7, 3);
    std::cout << b << std::endl;
    int i = 10;
    fooo(i);
    std::cout << i << std::endl;
    fo("Hello, world!");

}

void fo( std::string str){
    std::cout << str << std::endl;
}