//Написать обобщенную функцию сортировки методом Хоара и с ее помощью реализовать сортировку массивов типа double и Rect

#include <iostream>
#include <algorithm>

bool comparator(double a, double b) {
    return a < b; 
}

template <typename T>
void sort(T* arr, size_t size, bool(*compar)(T, T)) {
    std::sort(arr, arr + size, compar);
}

int main() {

    double arr[] = {3, 1, 4, 10, 2};
    const size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted array:\n";
    for(int i=0; i<5; i++)
    std::cout << arr[i] << std::endl;

    sort(arr, arr_size, comparator);

    std::cout << "Sorted array:\n";
    for(int i=0; i<5; i++)
        std::cout << arr[i] << std::endl;

}

 
