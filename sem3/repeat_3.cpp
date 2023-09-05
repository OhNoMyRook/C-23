#include <iostream>

struct ListPair{
    int data;
    ListPair *next;;
};

ListPair* add_node( ListPair *const head ){ //Добавить в начало (голову) списка
    return new ListPair {0, head};
}

ListPair* remove_node( ListPair *const head ){ //Удалить указанный
    if ( nullptr == head ) return head;
    auto new_head = head->next;
    delete head;
    return new_head;
}

void printlist( ListPair * head ){ //Печать списка в столбик
    while ( head != NULL){
        std::cout << head->data << " " ;
        head = head->next;   
    } 
    std::cout << "\n";  
}