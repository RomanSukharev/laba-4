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

    cout << "---���������� ������� ���������� ����������, ������� ������������� ��� ��������� �����---" << endl;
    random_values(array, S);
    output(array, S);

    cout << "---������� � �������� k-��� �������� � ������ �� ������ ���������� ������---" << endl;
    insert_element(array, S, 15, 2);
    output(array, S);

    selection_sort(array, S);
    bubble_sort(array, S);
    insertion_sort(array, S);
    cout << "---���������� �������, �� ����� ���� ����������, ������� ���� ���������� ����� ����������---" << endl;
    cout << "��������������� ������:" << endl;
    output(array, S);

    cout << "---����� ������� (��������) ������������� � ������������ �������� �������---" << endl;
    cout << "---����������� �������: " << array_min_element(array, S) << endl;
    cout << "---������������ �������: " << array_max_element(array, S) << endl; 
    output(array, S);


    cout << "---����� �������� ������� ���������� ��������� ������---" << endl;
    int q;
    cin >> q;
    cout << find(array, S, 0, q);
    cout << endl;
   

    cout << "---���������� ���������� ����� ��������� �������---" << endl;
    auto result = compute<int>(array, S, [](auto left, auto right) {return left + right; }, [](auto value) {return true; });
    cout << "����� ��������� ������� �������: " << result << endl;

    
    output_file_binary<int>(array, 5);
    output_file<int>(array, S);
    
   
  
    int A = max_module_element(array, S);
    cout << "�)������������ �� ������ �������: " << A << endl; ;
   
    array[1] = 0;
    array[4] = 0;
    int B = product_of_elements(array, S);
    cout << "�)������������ ����� fz � sz ���������:" << B << endl;
    output(array, S);
   
    
    
    cout << "�)������� ����� � ������� �� ���� �������� ��������� ���������:" <<  endl;
    cin >> a >> b;
    P = S - (b - a + 1);
    removeArr(array, array1, S, P, a, b);
    output(array1, P);
   
    return 0;
}
