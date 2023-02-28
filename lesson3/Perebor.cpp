#include <iostream>
#include <chrono>
#include <fstream>

int const n = 10000000 ;
int x = 102;
int array[n];

int func(int j){
    int i;

    srand(time(0)); 
 
    for (i = 0; i < j; i++)
        array[i] = rand()%100;
    
    for (i = 0; i < j; i++)
        if (array[i]==x){
            std::cout << "YES" << std::endl;
            break;
        }

    return 0; 
}
        
int main(){
    std::ofstream fout("amount1.txt");
    std::ofstream fuout("time1.txt");
    for (int j = 10000; j<n; j = j+10000){
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

  

