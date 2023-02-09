#include <iostream>

int fact( int n ){
    if ( n==0 ){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int i = fact(5);
    std::cout << i << std::endl;
}