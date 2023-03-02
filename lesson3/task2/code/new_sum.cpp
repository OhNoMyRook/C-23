#include <iostream>
#include <chrono>
#include <fstream>

int const n = 5000000 ;
int array[n];

int func(int j){
    int i;
    int x = rand()%100000;
    srand(time(0)); 
 
    for (i = 0; i <= j; i++)
        array[i] = i;

    int left = 0; 
    int right = j - 1; 
    while (left != right)
    {       
        int cursum = array[left] + array[right];
        if (cursum < x)
            left++;
        else if (cursum > x)
            right--;
        else{
            std::cout << "The first number is " << array[left] << " " << "The second number is " << array[right] << std::endl;
            return 0;
        }
    }
    std::cout << "There are no appropriate numbers" << std::endl;
    return 0;
}

int main(){
    std::ofstream fout("amount4.txt");
    std::ofstream fuout("time4.txt");
    for (int j = 1000; j<n; j = j+1000){
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