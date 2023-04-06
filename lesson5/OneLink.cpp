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

ListPair* add_after( ListPair *const head){ //Добавить после указанного хэдэра
    ListPair *temp, *p;
    temp = (ListPair*)malloc(sizeof(ListPair));
    p = head->next;
    head->next = temp;
    temp->next = p;
    return (temp);
}

void iter_delete(ListPair* &head){ //Итерационная функция удаления всего списка
    ListPair* prev = head;
    while (head){
        head = head->next;
        delete(prev);
        prev = head;
    }
}

void recurse_delete(ListPair* &head){ //Рекурсивная функция удаления всего списка
    if (head == nullptr) return;
    if (head->next) {
        recurse_delete(head->next);
    }
    delete(head);
    head = nullptr;
}

void iter_rotate(ListPair* &head){ //Итерационная функция переворота списка
    if (head == NULL) return;
    ListPair *curr, *temp, *prev = NULL;
    curr = head;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

ListPair* sorted;

void sortedInsert(ListPair* newnode){
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        ListPair* current = sorted;
        while (current->next != NULL && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void insertionSort(ListPair* &head){
    ListPair* current = head;
    sorted = NULL;
    while (current != NULL){
        ListPair* next = current->next;
        sortedInsert(current);
        current = next;
    }
    head = sorted;
}

int main(){
    auto head = add_node( nullptr );
    head->data = 0;
    head = add_node( head );
    head->data = 7;
    head = add_node( head );
    head->data = 2;
    auto temp = add_after( head );
    temp->data = 5;
    printlist( head );
    insertionSort( head );
    printlist( head );
    iter_rotate( head );
    printlist( head );
}