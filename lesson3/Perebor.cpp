#include <iostream>
#include <chrono>


int func(){
    int n;
    std::cout << "Input number :" << std::endl;
    std::cin >> n;
    int array[n];
    int i;

    srand(time(0)); 
 
    for (i = 0; i < n; i++)
        array[i] = rand()%100;
    
    int x = rand()%50;
    for (i = 0; i < n; i++)
        if (array[i]==x){
            break;
        }
    return 0;    
}

int main(){
    auto begin = std::chrono::steady_clock::now();
        func();
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin );

    std::cout << "\n\n";
    std::cout << "Complete time: " << time_span.count() << std::endl;
}

  

