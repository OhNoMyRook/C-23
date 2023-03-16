#include <iostream> 

bool sorted = false;

void forward_step( int array[], unsigned const begin_idx, unsigned const end_idx ){
    sorted = true;
    for( unsigned idx = begin_idx; idx <= end_idx - 1; idx++ )
            if (array[idx] > array[idx+1]){
                std::swap (array[idx], array[idx+1]);
                sorted = false;
            }                
}

void backward_step( int array[], unsigned const begin_idx, unsigned const end_idx ){
    sorted = true;    
    for( unsigned idx = end_idx; idx != begin_idx + 1; idx-- )
        if (array[idx] < array[idx-1]){
            std::swap (array[idx], array[idx-1]);
            sorted = false;
        }
}

void shaker_sort( int array[], unsigned const begin_idx, unsigned const end_idx ){
    while ( sorted == false ){
        forward_step( array, begin_idx, end_idx );
        backward_step( array, begin_idx, end_idx );
    }  
}

int main(){
    int array[20];
    int i;
    for (i = 0; i <= 19; ++i)
        array[i] = rand()%20;
    for( int i = 0; i <= 19; ++i )
        std::cout << array[i] << " ";
    std::cout << "\n";
    shaker_sort( array, 0, 19 );
    for( int i = 0; i <= 19; ++i )
        std::cout << array[i] << " ";
    return 0;
}
