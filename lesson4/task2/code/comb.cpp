#include <iostream>
#include <chrono>
#include <fstream>

int permutation = 0;

void fixed_step( int array[], int k, unsigned const begin_idx, unsigned const end_idx ){
    for( unsigned idx = begin_idx; idx <= end_idx-k; idx++ )
        if (array[idx] > array[idx+k]){
            std::swap (array[idx], array[idx+k]);
            permutation++;
        }
}

void some_steps( int array[], int j, unsigned const begin_idx, unsigned const end_idx ){
    for ( int l = j; l >= 2; l = l/2 )
        fixed_step( array, l, begin_idx, end_idx);
}

void bubble( int array[], unsigned const begin_idx, unsigned const end_idx ){
    bool sorted = false;
    while ( sorted == false ){
        sorted = true;
        for( unsigned idx = begin_idx; idx <= end_idx; idx++)
            if (array[idx] > array[idx+1]){
                std::swap (array[idx], array[idx+1]);
                sorted = false;
                permutation++;
            }
    }
}

int main(){
    std::ofstream fout("Amount");
    std::ofstream gout("Time");
    std::ofstream hout("Permutation");
    for ( int n = 100; n <= 10000; n = n + 100){
    int array[n];
    int i;
    for (i = 0; i <= n-1; ++i)
        array[i] = rand()%n;
    for( int i = 0; i <= n-1; ++i )
        std::cout << array[i] << " ";
    std::cout << "\n";
    auto begin = std::chrono::steady_clock::now();
    some_steps( array, n/2, 0, n-1);
    bubble( array, 0, n-1 );
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin );
    for( int i = 0; i <= n-1; ++i )
        std::cout << array[i] << " ";
    fout << n << ", ";
    gout << time_span.count() << ", ";
    hout << permutation << ", ";
    permutation = 0;
    }
    return 0;
}