#include "functions.hpp"



int main()
{
    setlocale(LC_ALL, "Russian");
    int S = 10;
    int* array = new int[S];
    int P = 10;
    int* array1 = new int[P];
    int a;
    int b;

    cout << "---Заполнение массива случайными значениями, включая специализацию для отдельных типов---" << endl;
    random_values(array, S);
    output(array, S);

    cout << "---Вставка и удаление k-ого элемента в массив на основе алгоритмов сдвига---" << endl;
    insert_element(array, S, 15, 2);
    output(array, S);

    selection_sort(array, S);
    bubble_sort(array, S);
    insertion_sort(array, S);
    cout << "---Сортировка массива, не менее трех алгоритмов, включая один улучшенный метод сортировки---" << endl;
    cout << "Отсортированный массив:" << endl;
    output(array, S);

    cout << "---Поиск номеров (индексов) максимального и минимального элемента массива---" << endl;
    cout << "---минимальный элемент: " << array_min_element(array, S) << endl;
    cout << "---максимальный элемент: " << array_max_element(array, S) << endl; 
    output(array, S);


    cout << "---Поиск элемента массива алгоритмом линейного поиска---" << endl;
    int q;
    cin >> q;
    cout << find(array, S, 0, q);
    cout << endl;
   

    cout << "---Вычисление количества суммы элементов массива---" << endl;
    auto result = compute<int>(array, S, [](auto left, auto right) {return left + right; }, [](auto value) {return true; });
    cout << "Сумма элементов первого массива: " << result << endl;

    
    output_file_binary<int>(array, 5);
    output_file<int>(array, S);
    
   
  
    int A = max_module_element(array, S);
    cout << "а)Максимальный по модулю элемент: " << A << endl; ;
   
    array[1] = 0;
    array[4] = 0;
    int B = product_of_elements(array, S);
    cout << "б)Произведение между fz и sz элеменами:" << B << endl;
    output(array, S);
   
    
    
    cout << "в)Сжимаем набор и удаляем из него элементы заданного интервала:" <<  endl;
    cin >> a >> b;
    P = S - (b - a + 1);
    removeArr(array, array1, S, P, a, b);
    output(array1, P);
   
    return 0;
}
