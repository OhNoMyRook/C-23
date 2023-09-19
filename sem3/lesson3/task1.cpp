//Создать класс Rect, содержащий 2 конструктора (по умолчанию и по двум концам диагонали) и 5 методов:
// 1) Переместить прямоугольник на заданный вектор
// 2) Изменить размер так, чтобы правый нижний угол остался неподвижным, параметры - новые длины сторон
// 3) Вывод параметров прямоугольника
// 4) Построить прямоугольник, равный пересечению данного и с заданными параметрами
// 5) Построить минимальный прямоугольник, содержащий данный и с заданными параметрами 

#include <iostream>

class Rect{
    private:
    // Координаты двух концов диагонали 
        int lx, ly, rx, ry;
    public:
        Rect(int lx, int ly, int rx, int ry): lx(lx), ly(ly), rx(rx), ry(ry){}
        Rect move_rect( int vect_x, int vect_y){ // В качестве аргументов - координаты вектора x и y, на который перемещаем
            Rect b(lx, ly, rx, ry); 
            lx+=vect_x;
            rx+=vect_x;
            ly+=vect_y;
            ry+=vect_y;
            return b;
        }
        void print_coordinates(){
            std::cout << lx << " " << ly << " " << rx << " " << ry << std::endl;
        }
};

int main(){

Rect a( 0, 0, 5, 3);
Rect b(0, 0, 0, 0);
b = a.move_rect( 1, 1 );
a.print_coordinates();
b.print_coordinates();

}