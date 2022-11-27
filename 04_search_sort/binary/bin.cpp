#include <iostream>
using namespace std;
int search(int arr[], int x, int y, int key)
{
	int mi;
	bool flag = false;
	while ((x <= y) && (flag != true)) {
		mi = (x + y) / 2;

		if (arr[mi] == key) flag = true; 
		if (arr[mi] > key) y = mi - 1; 
		else x = mi + 1;
	}
	return mi;
}
int main()
{
    int m[11] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; 
    const int arrsize = sizeof(m) / sizeof(m[0]); // находим длину массива
    cout << "Item ID: " << search(m, 0, arrsize, 19) << endl; // выводим количество найденных элементов и их номера
}