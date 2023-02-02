#include <iostream>

int main(){
    
    int a ;
    int b ;

    std::cout << "Input 1st number :" << std::endl;
    std::cin >> a;
    std::cout << "Input 2nd number :" << std::endl;
    std::cin >> b;
    
    while (a!=b){
        if( a>b ){
            a = a - b;
        }else{
            b = b - a;
        }
    }
    std::cout << "Your result: " << a << std::endl;
    return 0;
}
