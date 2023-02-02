#include <iostream>

int main() {
    int var = 10;
    std::cout << "Hello, world " << var << " " << sizeof(int) << std::endl;

    if(var){
        std::cout << var << std::endl;
    }else{
        std::cout << "Foo" << std::endl;
    }
    
    for( int i = 0 ; i<10 ; ++i ){
        std::cout << i << std::endl;
    }
    return 0;
}