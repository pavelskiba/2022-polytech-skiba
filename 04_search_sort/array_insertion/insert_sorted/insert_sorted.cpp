#include <iostream>
 
/**
 * Бинарный поиск первого неменьшего элемента.
 * (STL - std::lower_bound)
 */
template<class Iterator, class T, class Comparator = std::less<T>>
Iterator findLowerBound(Iterator first, Iterator last, const T& value, Comparator compare = Comparator()) {
    // если нужно без stl, можно заменить
    //auto count = last - first;
    auto count = std::distance(first, last);
 
    while (count > 0) {
        auto step = count / 2;
 
        // если нужно без stl, слдеюущие две строки замените на
        //auto it = first + step;
        auto it = first;
        std::advance(it, step);
 
        if (compare(*it, value)) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
 
    return first;
}
 
/**
 * Функция находит поизицию значения между двумя итераторами,
 * сдвигает с этой позиции все элементы вправо на один элемет,
 * записывая(!) в элемент last
 * и изменяет значение элемента на найденой позиции на value.
 *
 * @tparam Iterator -- тип итератора
 * @tparam T -- тип данных
 * @tparam Comparator -- тип функтора для сравнения элементов на "меньше"
 * @param first -- итератор на первый элемент диапазона
 * @param last -- итератор на последний фактический элемент диапазона
 * @param value -- добавнелнное значение
 * @param compare -- функция сравнения
 * @return итератор на позицию добавленного значения
 */
template<typename Iterator, typename T, typename Comparator = std::less<T>>
Iterator insertSorted(Iterator first, Iterator last, const T &value, Comparator compare = Comparator()) {
    Iterator position = findLowerBound(first, last, value, compare);
    for (Iterator i = last; position < i; --i) {
        *i = *(i - 1);
    }
    *position = value;
    return position;
}
 
int main() {
 
    int maxSize = 10; // количество заранее выделенных элементов
    int *array = new int[maxSize]; // хранилище выделенных элементов
 
    int size = 0; // количество добавленных по факту элементов оно всегда должно быть меньше maxSize 
 
    // собственно вставки в отсортированный массив:
    // обратите внимание, что с каждой вставкой увеличивается
    // количество добавленных по факту элементов
    insertSorted(array, array + size++, 5);
    insertSorted(array, array + size++, 3);
    insertSorted(array, array + size++, 7);
    insertSorted(array, array + size++, 4);
    insertSorted(array, array + size++, 6);
 
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
 
    delete[] array;
    return 0;
}