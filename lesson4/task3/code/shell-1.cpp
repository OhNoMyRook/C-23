#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>

int shellSort( int arr[], int N){
    int max = log2(N+1);
    for (int step = max; step > 0; step--){ 
        for (int i = step; i < N; i += 1){  
            int temp = arr[i]; 
            int j; 
            for (j = i; j >= step && arr[j - step] > temp; j -= step) 
                arr[j] = arr[j - step];             
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

int main(){
    std::ofstream fout("Amount-shell-1.txt");
    std::ofstream gout("Time-shell-1.txt");
    for ( int n = 10000; n <= 100000; n = n + 1000){
    int array[n];
    int i;
    for (i = 0; i <= n-1; ++i)
        array[i] = rand()%n;
    std::cout << "\n";
    auto begin = std::chrono::steady_clock::now();
        shellSort( array, n );
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin );
    fout << n << ", ";
    std::cout << n;
    gout << time_span.count() << ", ";
    }
    return 0;
}