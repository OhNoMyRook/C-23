#include <iostream>
#include <fstream>

int skob( std::string str, int n, int &s){
    if( str[n] == ')')
        s=s+1;
    if( str[n] == '(')
        s=s-1;
    return skob( str, n-1, s);    
}

int main(){

    int s = 0;
    std::ifstream fin("file.txt");
    std::string str;
    fin >> str;
    //std::cout << str.size() << std::endl;
    skob( str, str.size(), s);
    std::cout << s << std::endl;
}