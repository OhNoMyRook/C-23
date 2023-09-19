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
    for ( int i = 1; i<6; i++){
        std::cout << head->data << " " ;
        std::cout << "\n";
        head = head->next;   
    }  
}

int Flaviy( Ring *head, int m ){
    while( head != head->next){
        for (int i = 1; i < m; i++){
        head = head->next;
        }
        std::cout << "dead:" << head->next->data << '\n';
        head->next = head->next->next;
    }
    std::cout << "Last alive: " << head->data << '\n';
    return 0;
}

int main(){
    auto head = add_node( nullptr );
    head->data = 5;
    head = add_node( head );
    head->data = 4;
    head = add_node( head );
    head->data = 3;
    head = add_node( head );
    head->data = 2;
    head = add_node( head );
    head->data = 1;
    closure( head );
    printlist( head );
    Flaviy( head, 2);
}