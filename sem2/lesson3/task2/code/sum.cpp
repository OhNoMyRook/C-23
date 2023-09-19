#include <iostream>
#include <chrono>
#include <fstream>

int const n = 50001;

int array[n];

int func(int j){
    
    bool flag = false;
    int i;
    int l;
    int x = 260;
    srand(time(0)); 
 
    for ( i = 0; i < j; i++ )
        array[i] = rand()%100;

    for ( i = 0; i < j; i++ )
        for ( l = j; l > i; l-- )
            if ( (array[i] + array[l]) == x){
                std::cout << "First number is " << array[i] << " " << "Second number is " << array[l] << std::endl;
                flag = true;
                return 0;
            }
    if (flag == false)
        std::cout << "There are no appropriate numbers" << std::endl; 
    
    return 0; 
                 
}

int main(){
    std::ofstream fout("amount3.txt");
    std::ofstream fuout("time3.txt");
    for (int j = 100; j<n; j = j+100){
        auto begin = std::chrono::steady_clock::now();
        func(j);
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin );

        fuout << time_span.count() << ", ";
        fout << j << ", ";
    }
    return 0;
}
