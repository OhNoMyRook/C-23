//Придумать задачу, в которой использование шаблонов имеет смысл, и программа для решения которой потребует 200-300 строк кода. Написать решение к этой задаче

//Создать массив студентов. Данные студента - id, ФИ, факультет, группа, средний балл. Операции добавления/удаления студента, сортировка по фио, среднему баллу, вывод информации по id.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Student{

    private:
    int id;
    std::string name;
    std::string surname;
    std::string department;
    int course;
    int group;
    double average_point;

    public:
    Student(int in_id, std::string in_name, std::string in_surname, std::string in_department, int in_course, int in_group, double in_average_point){
        //Конструктор, принимает на вход айди студента, его имя и фамилию, факультет, курс, группу и средний балл
        id = in_id;
        name = in_name;
        surname = in_surname;
        department = in_department;
        course = in_course;
        group = in_group;
        average_point = in_average_point;
    }

    int get_id(){
        //Возвращает айди студента
        return id;
    }

    std::string get_name(){
        //Возвращает имя студента
        return name;
    }

    std::string get_surname(){
        //Возвращает фамилию студента
        return surname;
    }

    std::string get_department(){
        //Возвращает факультет студента
        return department;
    }

    int get_course(){
        //Возвращает курс, на котором учится студент
        return course;
    }

    int get_group(){
        //Возвращает номер группы, в которой учится студент
        return group;
    }

    double get_average_point(){
        //Возвращает средний балл студента
        return average_point;
    }
};

template<typename T>
class University{

    private:
    std::vector<T> data;

    public:

    University() {}
    void push(T item){
        //Добавление элемента (студента) в вектор университета
        data.push_back(item);
    }

    void erase(T item){
        //Удаление студента из вектора университета
        data.erase(item);
    }

    T info(int id){
        //Поиск студента в векторе по его айди
        for ( auto i = data.begin(); i < data.end(); i++){
        if ( i->get_id() == id)
            return *i;
        }
        std::cout << "There is no such student" << std::endl;
        return *data.end();
    }

    double info_average_point( int id ){
        //Возврат среднего балла студента с заданным айди
        return info(id).get_average_point();
    }

    std::string info_name( int id ){
        //Возврат имени студента с заданным айди
        return info(id).get_name();
    }

    std::string info_surname( int id ){
        //Возврат фамилии студента с заданным айди
        return info(id).get_surname();
    }

    std::string info_department( int id ){
        //Возврат факультета студента с заданным айди
        return info(id).get_department();
    }

    int info_group( int id ){
        //Возврат группы студента с заданным айди
        return info(id).get_group();
    }

    int info_course( int id ){
        //Возврат курса обучения студента с заданным айди
        return info(id).get_course();
    }

    void print_full_info(int id){
        //Вывод на экран полной информации о студенте с заданным айди
        std::cout << "Student with id " << id << "\n" << "Name: " << info_name(id) << "; " << "Surname: " << info_surname(id) << "; " << "Department: " << info_department(id) << "; " << "Course: " << info_course(id) << "; " << "Group: " << info_group(id) << "; " << "Average point: " << info_average_point(id) << std::endl;
    }

    void average_point_sort(){
        //Сортировка вектора по значению среднего балла студентов
        sort(data.begin(), data.end(), []( T & a,  T & b) -> bool{ 
            return a.get_average_point() > b.get_average_point(); 
        });
    }

    void surname_sort(){
        //Сортировка вектора по фамилиям студентов в алфавитном порядке
        sort(data.begin(), data.end(), []( T & a,  T & b) -> bool{ 
            return a.get_surname() < b.get_surname(); 
        });
    }

    void print_list_of_students(){
        //Вывод на экран списка всех студентов с их полной информацией
        for ( auto i = data.begin(); i < data.end(); i++){
            print_full_info(i->get_id());
    }
    }

};



int main(){

//Создаем 10 разных студентов

Student a(1, "Grigoriy" , "Ivanov" , "FOPF" , 8, 201, 10);
Student b(2, "Anna", "Smirnova", "BM", 2, 607, 6.1);
Student c(3, "Egor", "Semenov", "RT", 1, 102, 3.0);
Student d(4, "Ivan", "Baranov", "FUPM", 4, 527, 7.5);
Student e(5, "Liza", "Sazonova", "FEFM", 2, 409, 9.1);
Student f(6, "Sasha", "Limonov", "FAKI", 3, 305, 3.3);
Student g(7, "Natalia", "Belaya", "FIVT", 6, 502, 8.33);
Student h(8, "Oleg", "Romanov", "FALT", 5, 312, 5.48);
Student i(9, "Kirill", "Problemov", "FPFE", 6, 211, 7.99);
Student j(10, "Polina", "Rybakova", "FBVT", 1, 804, 9.99);

//Создаем элемент класса University (МФТИ) и заполяем его студентами

University<Student> MIPT;

MIPT.push(a);
MIPT.push(b);
MIPT.push(c);
MIPT.push(d);
MIPT.push(e);
MIPT.push(f);
MIPT.push(g);
MIPT.push(h);
MIPT.push(i);
MIPT.push(j);

//Проводим разные тестики и видим, что все работает, как надо

std::cout << "List of students before sorting by average mark: " << std::endl; 

MIPT.print_list_of_students();

MIPT.average_point_sort();

std::cout << "List of students after sorting by average mark: " << std::endl;

MIPT.print_list_of_students();

MIPT.surname_sort();

std::cout << "List of students after sorting by surname: " << std::endl;

MIPT.print_list_of_students();

std::cout << MIPT.info_average_point(1) << std::endl;
std::cout << MIPT.info_department(3) << std::endl;
std::cout << MIPT.info_surname(10) << std::endl;
MIPT.print_full_info(2);
MIPT.print_full_info(4);
MIPT.print_full_info(9);

return 0;

}