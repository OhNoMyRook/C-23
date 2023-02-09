#include <iostream>
#include <fstream>

int main(){

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::string str = "Hello";


    int a;
    int b = 100;

    fin >> a;
    fout << b;

    std::cout << a << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str[3] << std::endl;

}