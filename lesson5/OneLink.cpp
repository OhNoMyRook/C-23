#include <iostream>

struct ListPair{
    int data;
    ListPair *next;;
};

ListPair* add_node( ListPair *const head ){
    return new ListPair {0, head};
}

ListPair* remove_node( ListPair *const head ){
    if ( nullptr == head ) return head;
    auto new_head = head->next;
    delete head;
    return new_head;
}

void Printlist( ListPair * head ){
    while ( head != NULL){
        std::cout << head->data << " " << std::endl;
        head = head->next;
    }   
}

ListPair* add_after( ListPair *const head){
    ListPair *temp, *p;
    temp = (ListPair*)malloc(sizeof(ListPair));
    p = head->next;
    head->next = temp;
    temp->next = p;
    return (temp);
}

int main(){
    auto head = add_node( nullptr );
    head->data = 0;
    auto head_1 = add_node( head );
    head_1->data = 1;
    auto head_2 = add_node( head_1 );
    head_2->data = 2;
    auto temp = add_after( head_1 );
    temp->data = 5;
    Printlist ( head_2 );
}