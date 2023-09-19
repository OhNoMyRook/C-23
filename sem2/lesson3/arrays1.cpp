#include <iostream>

int main(){

    int array[3] = { 1, 2, 3 };
    std::cout << array[2] << std::endl;
    for( int i = 0; i < 3; ++i ){
        std::cout << array[i] << " ";
    }
    return 0;

}