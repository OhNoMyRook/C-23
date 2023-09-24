//Создать класс Rect, содержащий 2 конструктора (по умолчанию и по двум концам диагонали) и 5 методов:
// 1) Переместить прямоугольник на заданный вектор
// 2) Изменить размер так, чтобы правый нижний угол остался неподвижным, параметры - новые длины сторон
// 3) Вывод параметров прямоугольника
// 4) Построить прямоугольник, равный пересечению данного и с заданными параметрами
// 5) Построить минимальный прямоугольник, содержащий данный и с заданными параметрами 

#include <iostream>

class Rect{
    private:
    // Координаты двух концов диагонали: левый нижний и правый верхний
        int lx, ly, rx, ry;
    public:
        Rect(int in_lx, int in_ly, int in_rx, int in_ry){
        // Конструктор по двум концам диагонали
            lx = in_lx;
            ly = in_ly;
            rx = in_rx;
            ry = in_ry;
        }

        Rect(){
        // Конструктор по умолчанию: создает единичный квадрат
            lx = 0;
            ly = 0;
            rx = 1;
            ry = 1;
        }

        Rect move_rect(int vect_x, int vect_y){ 
        // В качестве аргументов - координаты вектора по x и по y, на который перемещаем, возвращает координаты концов диагонали нового прямоугольника
            int new_lx = lx+vect_x;
            int new_rx = rx+vect_x;
            int new_ly = ly+vect_y;
            int new_ry = ry+vect_y;
            Rect rect(new_lx, new_ly, new_rx, new_ry);
            return rect;
        }

        Rect resize_rect(int x, int y){ 
        // В качестве аргументов - размеры x и y нового прямоугольника, возвращает координаты концов диагонали прямоугольника, 
        // у которого правый нижний угол совпадает с правым нижним углом изменяемого прямоугольника
            int new_lx = rx-x;
            int new_ry = ry-y;
            Rect rect (new_lx, ly, rx, new_ry);
            return rect; 
        }

        void print_coordinates(){
        // Печатает координаты левого нижнего и правого верхнего угла прямоугольника
            std::cout << lx << " " << ly << " " << rx << " " << ry << std::endl;
        }

        Rect intersection( int lx_given, int ly_given, int rx_given, int ry_given ){
        // В качестве аргументов координаты параметризованного прямоугольника. Возвращает прямоугольник-пересечение данного и с параметрами, если пересечения нет - нули
            int new_lx, new_ly, new_rx, new_ry;
            if(rx_given < lx || ry_given < ly || lx_given > rx || ly_given > ry){
                new_lx = 0;
                new_ly = 0;
                new_rx = 0;
                new_ry = 0;
            }else{
            new_lx = std::max(lx_given, lx);
            new_ly = std::max(ly_given, ly);
            new_rx = std::min(rx_given, rx);
            new_ry = std::min(ry_given, ry);
            }
            Rect rect(new_lx, new_ly, new_rx, new_ry);
                return rect;
            }

        Rect unity( int lx_given, int ly_given, int rx_given, int ry_given ){
            // В качестве параметров - координаты параметризованного прямоугольника. Возвращает минимальный прямоугольник, содержащий данный и с параметрами
            int new_lx = std::min(lx_given, lx);
            int new_ly = std::min(ly_given, ly);
            int new_rx = std::max(rx_given, rx);
            int new_ry = std::max(ry_given, ry);
            Rect rect(new_lx, new_ly, new_rx, new_ry);
                return rect;
        }
};

int main(){

Rect a(0, 0, 5, 3);
Rect b = a.move_rect( 1, 1 );
Rect c = b.move_rect( 7, -1);
Rect d = c.resize_rect(2, 1);
Rect e;
Rect f = a.intersection(3, 1, 10, 2);
Rect g = a.intersection(6, 1, 7, 2);
Rect h = a.intersection(-3, -3, 0, 20);
Rect i = a.unity(-1, 1, 6, 4);
Rect j = a.unity(-3, -3, 4, 2);
a.print_coordinates();
b.print_coordinates();
c.print_coordinates();
d.print_coordinates();
e.print_coordinates();
f.print_coordinates();
g.print_coordinates();
h.print_coordinates();
i.print_coordinates();
j.print_coordinates();

}