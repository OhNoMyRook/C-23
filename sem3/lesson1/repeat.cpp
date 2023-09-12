#include <iostream>

int main(){

    int array_1[5] = { 7, 5, 8, 1, 4};
    int array_2[5] = { 13, 2, 9, 11, 3};
    int array_sum[5];

    for ( int i=0; i<5; i++){

        *(array_sum+i) = *(array_1+i) + *(array_2+4-i);
    
    }
    
    for ( int i=0; i<5; i++){
        std::cout << *(array_sum+i) << std::endl;
    }

}