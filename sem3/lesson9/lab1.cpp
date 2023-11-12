#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <unordered_set>

template <typename T, typename Compare = std::less<T>>
class CustomList {
private:
    std::list<T> internalList;  // Internal list to store elements
    Compare comparator;         // Comparator for custom ordering
public:
    // 1. Наличие конструктора по умолчанию для пустого списка
    CustomList() {}

    // 2. Наличие конструктора от диапазона итератора
    template <typename InputIterator>
    CustomList(InputIterator begin, InputIterator end) : internalList(begin, end) {}

    // 3. Наличие конструктора копирования и оператора копирующего присваивания
    CustomList(const CustomList& other) : internalList(other.internalList), comparator(other.comparator) {}

    CustomList& operator=(const CustomList& other) {
    if (this != &other) {
        internalList = other.internalList;
        comparator = other.comparator;
    }
    return *this;
    }

    // 4. Наличие эффективных конструктора перемещения и перемещающего присваивания
    CustomList(CustomList&& other) noexcept : internalList(std::move(other.internalList)), comparator(std::move(other.comparator)) {}

    CustomList& operator=(CustomList&& other) noexcept {
    if (this != &other) {
        internalList = std::move(other.internalList);
        comparator = std::move(other.comparator);
    }
    return *this;
    }

    // 5. Наличие метода empty, возвращающего true, если список пуст
    bool empty() const {
        return internalList.empty();
    }

    // 6. Наличие метода size, возвращающего текущее количество элементов
    size_t size() const {
        return internalList.size();
    }

        // 7. Наличие метода insert для вставки нового значения с амортизированной сложностью
    void insert(const T& value) {
        internalList.insert(std::upper_bound(internalList.begin(), internalList.end(), value, comparator), value);
    }

    // 8. Наличие перегруженного метода insert для вставки диапазона итераторов
    template <typename InputIterator>
    void insert(InputIterator begin, InputIterator end) {
        internalList.insert(internalList.end(), begin, end);
        internalList.sort(comparator);
    }

    // 9. Наличие итератора для обхода списка в отсортированном порядке
    //    и удовлетворяющего требованиям bidirectional iterator
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    typename std::list<T>::iterator iter;
    public:
    iterator(typename std::list<T>::iterator it) : iter(it) {}

    bool operator==(const iterator& other) const {
        return iter == other.iter;
    }

    bool operator!=(const iterator& other) const {
        return iter != other.iter;
    }

    typename iterator::reference operator*() const {
        return *iter;
    }

     iterator& operator++() {
        ++iter;
        return *this;
    }

    iterator operator++(int) {
        iterator temp = *this;
        ++(*this);
        return temp;
    }

    iterator& operator--() {
        --iter;
        return *this;
    }

    iterator operator--(int) {
        iterator temp = *this;
        --(*this);
        return temp;
    }
    };

    iterator begin() {
        return iterator(internalList.begin());
    }

    iterator end() {
        return iterator(internalList.end());
    }

    // 10. Наличие специального итератора для обхода списка в обратном направлении
    class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    typename std::list<T>::reverse_iterator iter;
    public:
    reverse_iterator(typename std::list<T>::reverse_iterator it) : iter(it) {}

    bool operator==(const reverse_iterator& other) const {
        return iter == other.iter;
    }

    bool operator!=(const reverse_iterator& other) const {
        return iter != other.iter;
    }

    typename reverse_iterator::reference operator*() const {
        return *iter;
    }

    reverse_iterator& operator++() {
        ++iter;
        return *this;
    }

    reverse_iterator operator++(int);

    // 11. Наличие метода find для поиска положения ключа в списке
    find(const T& key) {
    auto it = std::lower_bound(internalList.begin(), internalList.end(), key, comparator);
    if (it == internalList.end() || comparator(key, *it)) {
    return internalList.end(); // Key not found
    }
    return iterator(it);
    }

    // 12. Наличие метода count, возвращающего количество вхождений заданного ключа
    count(const T& key){
    auto range = std::equal_range(internalList.begin(), internalList.end(), key, comparator);
    return std::distance(range.first, range.second);
    }

    // 13. Наличие метода lower_bound, возвращающего итератор на первый элемент не меньше заданного
    lower_bound(const T& key) {
    return iterator(std::lower_bound(internalList.begin(), internalList.end(), key, comparator));
    }

    // 14. Наличие метода upper_bound, возвращающего итератор на первый элемент строго больше заданного
    upper_bound(const T& key) {
    return iterator(std::upper_bound(internalList.begin(), internalList.end(), key, comparator));
    }

    // 15. Наличие метода clear для удаления всех элементов списка
    clear() {
    return internalList.clear();
    }

   // 16. Наличие метода erase для удаления элемента из списка по итератору
    erase(iterator position) {
    return iterator(internalList.erase(position.iter));
    }

    // 17. Наличие перегруженного метода erase для удаления промежутка итераторов
    erase(iterator first, iterator last) {
    return iterator(internalList.erase(first.iter, last.iter));
    }
    // 18. Возможность создания списка с произвольным компаратором
     
    // (((

    // 19. Возможность хранения повторяющихся элементов в списке
    // (предусмотрено по умолчанию, так как std::list поддерживает дубликаты)

    // 20. Метод equal_range, возвращающий промежуток итераторов на равные заданному ключу элементы
    equal_range(const T& key) {
    return std::equal_range(internalList.begin(), internalList.end(), key, comparator);
    }
};
};

// Example usage:
int main() {
    return 0;
}