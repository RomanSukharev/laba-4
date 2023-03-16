#pragma once 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

// заполнение массива случайными значениями, включая специализацию для отдельных типов
template<typename T>
void random_values(T* array, int size)
{
    srand(time(nullptr)); //чтобы были разные числа
    for (int i = 0; i < size; ++i)
    {
        array[i] = static_cast<T>(rand() % 200 - 100); //осуществляет явное допустимое приведение типа данных
    }
}

//------------------------------------------------------------------------------------------------------------------

// Вставка и удаление k-ого элемента в массив на основе алгоритмов сдвига;
// Массив должен быть способен вместить как минимум size + 1 элемент
template<typename T>
void insert_element(T* array, int size, T elem, int pos)
{
    if (pos > size)
        pos = size;

    // Сдвигаем все элементы с конца массива до позиции pos вправо на 1 элемент
    for (int i = size - 1; i > pos; --i)
        array[i] = array[i - 1];

    // В позицию pos записываем элемент elem
    array[pos] = elem;
}

// Удаление элемента из массива
template<typename T>
void array_delete(T* array, int size, int pos)
{
    // Сдвигаем все элементы, начиная с позиции pos и до конца массива на 1
    // элемент влево
    for (int i = pos; i < size - 1; ++i)
        array[i] = array[i + 1];
}

//------------------------------------------------------------------------------------------------------------------

//Сортировка массива, не менее трех алгоритмов, включая один улучшенный метод сортировки;

//Пузырьковая сортировка +
template<typename T>
void bubble_sort(T* array, T size)
{
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        // ЕСЛИ никакие два элемента не были заменены внутренним циклом, то разрыв
        if (swapped == false)
            break;
    }
}
//Сортировка выбором +
template<typename T>
void selection_sort(T* array, T size)
{
   for (int i = 0; i < size; i++)
   {
      int j = i;
      // найти наименьшее целое число от a[i] до a[n-1]
      for (int k = i + 1; k < size; k++)
      if (array[k] < array[j]) { j = k; }
      swap(array[i], array[j]);
   }
}

//Сортировка вставками +
template<typename T>
void insertion_sort(T* array, T size)
{
    int i = 0, j;
    T temp;

    for (int i = 1; i < size; ++i)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}
//------------------------------------------------------------------------------------------------------------------
//поиск номеров (индексов) максимального и минимального элемента массива;
// Поиск минимального элемента
template<typename T>
T array_min_element(const T* array, int size)
{
    T min = array[0];

    for (int i = 1; i < size; ++i)
        if (min > array[i])
            min = array[i];

    return min;
}

//template<typename T>
//bool _moreZero(T i) { return i != 0; }
//
//template<typename T>
//T sort_zero(T* array, int size, bool (*pred)(T)){
//    for (int i = 0; i < size; i++) {
//        if ((*pred)(array[i])) {
//            return array[i];
//        }
//    }
//}

//template<typename T>
//bool _max_el(T a, T b){ return a < b}
//
//template<typename T>
//T array_max_element_2(const T* array, int size, )
//{
//    T max = array[0];
//
//    for (int i = 1; i < size; ++i)
//        if (max < array[i])
//            max = array[i];
//
//    return max;
//}

// Поиск максимального элемента
template<typename T>
T array_max_element(const T* array, int size)
{
    T max = array[0];

    for (int i = 1; i < size; ++i)
        if (max < array[i])
            max = array[i];

    return max;
}
//------------------------------------------------------------------------------------------------------------------
// поиск элемента массива алгоритмом линейного и бинарного поиска (итерационная и рекурсивная реализация);
template<typename T>
const T* array_find(const T* array, int size, const T& value)
{
    for (const T* p = array; p != array + size; ++p)
        if (*p == value)
            return p;
    return 0;
}
template<typename T>
int find(T* array, int size, int start, T element)
{
    for(int i = start; i < size; ++i)
    {
        if(array[i] == element)
            return i;
    }
    return -1;
}

//------------------------------------------------------------------------------------------------------
//вычисление количества, суммы и произведения элементов массива с указанной характеристикой
template<typename T>
T compute(T* array, int size, T(*operation)(T left, T right), bool(*filter)(T value))
{
    T result = array[0];

    for(int i = 1; i < size; ++i)
    {
        if(filter(array[i]))
            result = operation(result, array[i]);
    }

    return result;
}
//-----------------------------------------------------------------------------------------------------------
//ввод/вывод массива потоками стандартными и файловыми.
template<typename T>
void input(T* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
}

template<typename T>
T* input_file()
{
    ifstream file("output.txt");
    T* array;
    int size;

    file >> size;
    array = new T[size];

    for (int i = 0; i < size; ++i)
    {
        file >> array[i];
    }

    return array;
}

template<typename T>
T* input_file_binary()
{
    ifstream file("output.data");

    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    T* array = new T[size];

    for (int i = 0; i < size; ++i)
    {
        file.read(&array[i], sizeof(T));
    }

    return array;
}

template<typename T>
void output(T* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "[" << i << "]" << " = " << array[i] << endl;
    }
}

template<typename T>
void output_file(T* array, int size)
{
    ofstream file("output.txt");

    file << size << endl;
    for (int i = 0; i < size; ++i)
    {
        file << array[i] << endl;
    }
}

template<typename T>
void output_file_binary(T* array, int size)
{
    ofstream file("output.data");

    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    for (int i = 0; i < size; ++i)
    {
        file.write(reinterpret_cast<char*>(&array[i]), sizeof(T));
    }
}

// Задания по 6 варианту 
// а) Максимальный по модулю элемент;
template<typename T>
T max_module_element(T* array, int size)
{
    //abs
    //min max по предикату
   int max = 0, temp;

    for (int i = 0; i < size; i++)
    {
        if (array[i] >= 0)
            temp = array[i];
        else
            temp = -array[i];

        if (max < temp)
            max = temp;
    }
    return max;
}




//б) Произведение элементов, расположенных между первым и вторым нулевыми элементами.
template<typename T>
T product_of_elements(T* array, int size)
{
    int firstzero = find(array, size, 0, 0); //индекс 1-ого 0 элемента
    int secondzero = find(array, size, firstzero + 1, 0); //индекс 2-ого 0 элемента
    T product = 1;
    for (int i = firstzero + 1; i < secondzero; i++)
    {
        product *= array[i];
    }
    return product;
    
   
}

//в) Cжать набор, удалив из него элементы заданного интервала номеров
template<typename T>
T removeArr(T* array,T* array1, T S, T P, T a, T b)
{
    for (T i = 0; i < S; i++)
    {
        if (i < a)
        {
            array1[i] = array[i];
        }

        if (i > b)
        {
            array1[i - (b - a) - 1] = array[i];
        }
    }

    return *array1;
}
