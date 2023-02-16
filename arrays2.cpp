#include <iostream>

#define SIZE 1024

void foo( int (&array)[SIZE] ){
    std::cout << sizeof(array) << std::endl;
}

int main(){
    int array[SIZE];

    foo( array );
}