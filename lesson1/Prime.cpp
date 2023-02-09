#include <iostream>
#include <cmath>

int main(){
    
    double a;

    std::cout << "Input number :" << std::endl;
    std::cin >> a;

    double b;
    double c;

    b = sqrt(a);
    
    int i;
    int s = 0;

    for( i=2; i<b+1; i++ ){
        c = a/i;
        if (c == (long long)c){
            s++;
        }else{
            continue;
        }
    }

    if (s==0){
        std::cout << "It's a prime number" << std::endl;
    }else{
        std::cout << "It isn't a prime number" << std::endl;
    }

    return 0;

}