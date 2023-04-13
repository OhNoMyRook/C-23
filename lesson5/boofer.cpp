#include <iostream>

struct Ring{
    int data;
    Ring *next;
};

Ring* add_node( Ring *const head ){ 
    return new Ring {0, head};
}

void closure( Ring *head ){
    auto new_head = head;
    while ( head->next != NULL){
        head = head->next;
        continue;
    }
    if ( head->next == NULL ){
        head->next = new_head;
    }
}

void printlist( Ring * head ){ 
    for ( int i = 1; i<16; i++){
        std::cout << head->data << " " ;
        head = head->next;   
    }  
}

int main(){
    auto head = add_node( nullptr );
    head->data = 0;
    head = add_node( head );
    head->data = 7;
    head = add_node( head );
    head->data = 2;
    head = add_node( head );
    head->data = 11;
    head = add_node( head );
    head->data = 78;
    closure( head );
    printlist( head );
}