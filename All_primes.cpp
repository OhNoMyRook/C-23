#include <iostream>
#include <cmath>

int main(){
    
    double a;
    double b;
    double c;
    int max;
    std::cout << "Input number :" << std::endl;
    std::cin >> max;

    int i;
    int s = 0;

    for ( a=1; a<=max; a++){
        b = sqrt(a);
        for( i=2; i<=b; i++ ){
            c = a/i;
            if (c == (long long)c){
                s++;
            }
        }
    
        if (s==0){
            std::cout << a << std::endl;
        }
        s = 0;
    }

    return 0;

}