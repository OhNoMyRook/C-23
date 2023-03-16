#include <iostream>
#include <chrono>
#include <fstream>

int const n = 10000000 ;
int x = 10000001;
int array[n];

int func(int j){
    int i;

    srand(time(0)); 
 
    for (i = 0; i <= j; i++)
        array[i] = i;

    bool flag = false;    
    int left = 0; 
    int right = j; 
    int middle;

    while ((left <= right) && (flag != true)){
        middle = (left + right) / 2; 
        if (array[middle] == x) flag = true; 
        if (array[middle] > x) right = middle - 1; 
        else left = middle + 1;
    }
    if (flag == true) 
        return 0;     
}

int main(){
    std::ofstream fout("amount2.txt");
    std::ofstream fuout("time2.txt");
    for (int j = 10000; j<=n; j = j+10000){
        auto begin = std::chrono::steady_clock::now();
        for (int k = 0; k<=10; k++)
            func(j);
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin );

        fuout << time_span.count()/10 << ", ";
        fout << j << ", ";
    }
    return 0;
}