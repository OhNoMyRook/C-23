#include <iostream>

template <typename T>

class Grid final {
    using value_type = T;
    using size_type = unsigned ;

    private :
        T *  data ; //Одномерный массив для ()-индексирования
        size_type y_size , x_size ;
        T** data1; //Многомерный (двумерный) массив - для [][] индексирования
    public:

        //Конструктор по умолчанию
        Grid() : x_size(1), y_size(1), data(new T[1]()),  data1(new T*[1]()) {
            data1[0] = new T[1]();
        }

        Grid (T *data , size_type const y_size , size_type const x_size ) :
        data ( data ) , y_size ( y_size ) , x_size ( x_size ), data1(new T*[y_size]()) { 
            for(int i=0; i<y_size; i++){
                data1[i] = new T[x_size]();
                for(int j=0; j<x_size; j++){
                    data1[i][j] = data[i*x_size+j];
                }
            }
        }
        
        //Неявное преобразование типов
        Grid (T const &t) : x_size(1), y_size(1), data(new T[1]()),  data1(new T*[1]()){
            data[0] = T(t);
            data1[0] = new T[1]();
            data1[0][0] = T(t);
        }

        //Конструктор с двумя параметрами
        Grid(size_type const y_size, size_type const x_size) : x_size(x_size), y_size(y_size), data(new T[x_size*y_size]()),  data1(new T*[y_size]()){
            for(int i=0; i<y_size; i++){
                data1[i] = new T[x_size]();
            }
        }

        //Конструктор с тремя параметрами
        Grid(size_type const y_size, size_type const x_size, T const &t) : x_size(x_size), y_size(y_size), data(new T[x_size*y_size]()),  data1(new T*[y_size]()){
            for(int i=0; i < x_size*y_size; i++){
                data[i] = T(t);
            }
            for(int i=0; i<y_size; i++){
                data1[i] = new T[x_size]();
                for(int j=0; j<x_size; j++){
                    data1[i][j] = data[i*x_size+j];
                }
            }
        }

        //Конструктор копирования
        Grid (Grid<T> const &Grid1): data(new T[Grid1.x_size*Grid1.y_size]()), x_size(Grid1.x_size), y_size(Grid1.y_size), data1(new T*[Grid1.y_size]()){
            for(int i=0; i < (Grid1.x_size)*(Grid1.y_size); i++){
                (this->data)[i] = (Grid1.data)[i];
            }
            for(int i=0; i<y_size; i++){
                data1[i] = new T[x_size]();
                for(int j=0; j<x_size; j++){
                    data1[i][j] = data[i*x_size+j];
                }
            }
        }
            
        //Конструктор перемещения
        Grid (Grid<T>&&Grid1): data(Grid1.data), x_size(Grid1.x_size), y_size(Grid1.y_size), data1(Grid1.data1){
            Grid1.x_size = 0;
            Grid1.y_size = 0;
            Grid1.data = nullptr;
            Grid1.data1 = nullptr;
        }
            
        //Копирующее присваивание
        Grid<T>& operator=(Grid<T>&Grid1) {
            Grid<T> tmp(Grid1);
            std::swap(this->data1, tmp.data1);
            std::swap(this->data, tmp.data);
            std::swap(this->x_size, tmp.x_size);
            std::swap(this->y_size, tmp.y_size);
        }

        //Перемещающее присваивание
        Grid<T>& operator=(Grid<T>&&Grid1) {
            Grid<T> tmp(std::move(Grid1));
            std::swap(this->data1, tmp.data1);
            std::swap(this->data, tmp.data);
            std::swap(this->x_size, tmp.x_size);
            std::swap(this->y_size, tmp.y_size);
        } 

        T operator ( ) ( size_type y_idx , size_type x_idx ) const {
        return data [ y_idx * x_size + x_idx ] ;
        }

        T& operator ( ) ( size_type y_idx , size_type x_idx ) {
        return data [ y_idx * x_size + x_idx ] ;
        }

        Grid<T>& operator=(T const &t ) {
        for (auto it = data , end = data + x_size * y_size ;it != end ; ++it)
            *it = t ;
        for(int i=0; i<y_size; i++){
                for(int j=0; j<x_size; j++){
                    data1[i][j] = t;
                }
            }
        return * this ;
        }

        T* operator[](int i) const {
            return data1[i];
        }

        void set_val(size_type y_idx, size_type x_idx, T val){
            (*this)(y_idx,x_idx) = val;
            data1[y_idx][x_idx] = val;
        }

        //Деструктор
        ~Grid(){
            delete[] data;
            for(int i=0;i<y_size;i++){
                delete[] data1[i];
            }
            delete[] data1;
        }

        size_type get_y_size ( ) const { return y_size ; }
        size_type get_x_size ( ) const { return x_size ; }

        void print(){
            if(data1){
                for(int i=0; i<y_size; i++){
                for(int j=0; j<x_size; j++){
                    std::cout << data1[i][j] << " ";
                }
            }
            std::cout << std::endl;
            }else{
                std::cout << "Grid is empty" << std::endl;
            }
            
        }
} ;

int main(){
    Grid<int> g1(2,4,5);
    g1.print();
    Grid<int> g2(g1); //Конструктор копирования
    g2.print();

    g1.set_val(1,3,-90); //Изменение элемента
    g1.print();
    g2.print();

    Grid<int> g3(9); //Неявное преобразование
    g3.print();
    Grid<int> g4(3,3);
    g4.print();

    Grid<int> g5 = g4; //Копирующее присваивание
    g4.set_val(1,0,77);

    g4.print();
    g5.print();
    g5 = 4;
    std::cout << g4[1][0] << std::endl;
    g5.print();

    Grid<int> g6(std::move(g5)); //Конструктор перемещения
    g6.print();
    g5.print();
    Grid<int> g7 = std::move(g6);
    g7.print();
    g6.print();
    g5.print();
}