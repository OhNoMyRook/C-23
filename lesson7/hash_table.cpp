#include <iostream>
#include <chrono>
#include <fstream>


struct for_hash{
    std::string name;
    for_hash* next = nullptr;
    for_hash* prev = nullptr;
};


for_hash* adress;


for_hash* create(int N){
    for_hash* hash_table = new for_hash[N];
    return hash_table;
}


int hash(std::string name, int N) {
    int sum = 0;
    for (int i = 0; i < name.size(); i++) {
        sum += ((int)name[i]+2*N);
    }
    return sum%N;
}


for_hash* Add(std::string name, for_hash* hash_table, int N, int s) {
    for_hash* curr = &hash_table[hash(name, N)];
    while (curr->next!= nullptr) {
       curr = curr->next;
    } 
    for_hash* new_elem = new for_hash;
    new_elem->name = name;
    new_elem->prev = curr;
    curr->next = new_elem;   
    s+=1; 
    return hash_table;
}


int If_empty(for_hash* hash_table, int N){
    for (int i = 0; i < N; i++) {
        if (hash_table[i].next != nullptr) {
            std::cout << "Not empty" << std::endl;
            return 0;
        }
    }
    std::cout << "Empty" << std::endl;
    return 0;
}


for_hash* Search(std::string name, for_hash* hash_table, int N) {
    for_hash* ptr = hash_table[hash(name, N)].next;
    while( ptr != nullptr ){
        if ( ptr->name == name) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}


bool Result(std::string name, for_hash* hash_table, int N) {
    if ( Search( name, hash_table, N) != nullptr ) {
        return true;
    }
    else {
        return false;
    }

}


int Delete(std::string name, for_hash* hash_table, int N){
    auto ptr = Search(name, hash_table, N);
    if ((ptr->prev)!=nullptr ) {
        (ptr->prev)->next = ptr->next;
    }
    if ((ptr->next)!=nullptr) {
        (ptr->next)->prev = ptr->prev;
    }
    delete ptr;
    return 0;
}

void Delete_Table(std::string name, for_hash* hash_table, int N){
    auto ptr = Search(name, hash_table, N);
    while ( ptr->next != nullptr ){
        auto curr = ptr->next;
        delete ptr;
        ptr = curr;
    }
}

int main(){
    int s = 0;
    int N = 1100;
    adress = create(N);
    Add("Ben", adress, N, s);
        if ( s >= 0.8*N ){
            s = 0;
            Delete_Table("Ben", adress, N);
            N = 2*N;
            adress = create(N);
            Add("Ben", adress, N, s);
        }
    Add("Jim", adress, N, s);
        if ( s >= 0.8*N ){
            s = 0;
            Delete_Table("Jim", adress, N);
            N = 2*N;
            adress = create(N);
            Add("Ben", adress, N, s);
            Add("Jim", adress, N, s);
            }
    Add("Kate", adress, N, s);
        if ( s >= 0.8*N ){
            s = 0;
            Delete_Table("Kate", adress, N);
            N = 2*N;
            adress = create(N);
            Add("Ben", adress, N, s);
            Add("Jim", adress, N, s);
            Add("Kate", adress, N, s);
            }
    Add("Sam", adress, N, s);
         if ( s >= 0.8*N ){
            s = 0;
            Delete_Table("Sam", adress, N);
            N = 2*N;
            adress = create(N);
            Add("Ben", adress, N, s);
            Add("Jim", adress, N, s);
            Add("Kate", adress, N, s);
            Add("Sam", adress, N, s);
            }
    Add("Jess", adress, N, s);
        if ( s >= 0.8*N ){
            s = 0;
            Delete_Table("Sam", adress, N);
            N = 2*N;
            adress = create(N);
            Add("Ben", adress, N, s);
            Add("Jim", adress, N, s);
            Add("Kate", adress, N, s);
            Add("Sam", adress, N, s);
            Add("Jess", adress, N, s);
            }
    

    Delete("Sam", adress, N);

    if( Result("Sam", adress, N) )
        std::cout << "in table" << std::endl;
    else
        std::cout << "not in table" << std::endl;
    If_empty(adress, N);   

    std::ofstream fout("amount.txt");
    std::ofstream fuout("time.txt");
    std::ofstream gout("amount-1.txt");
    std::ofstream guout("time-1.txt");
    for (int j = 1; j<=10000; j = j+1){
        auto begin = std::chrono::steady_clock::now();
            Add(std::to_string(j), adress, N, s);
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin );

        fuout << time_span.count() << ", ";
        fout << j << ", ";

        auto begin_1 = std::chrono::steady_clock::now();
            Search(std::to_string(j+1), adress, N);
        auto end_1 = std::chrono::steady_clock::now();
        auto time_span_1 =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_1 - begin_1 );

        guout << time_span_1.count() << ", ";
        gout << j << ", ";
    }

    return 0;
}
