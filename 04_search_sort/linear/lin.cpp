#include <iostream>
using namespace std;
int search(int arr[], int n, int x, int result[])
{
    int a = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == x)
        {
            result[a] = i;
            a++;
        }
    }
    return a;
}
int main()
{
    int m[11] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 19}; 
    const int arrsize = sizeof(m) / sizeof(m[0]); // находим длину массива
    int result[arrsize]; // создаём массив result и заполняем его нулями
    for (int i = 0; i < arrsize; ++i)
    {
        result[i] = 0;
    }
    cout << "Count: " << search(m, arrsize, 19, result) << endl << "id : " << endl; // выводим количество найденных элементов и их номера
    for (int i = 0; i < arrsize; ++i)
    {
        cout << result[i] << endl;
    }
}