#include <iostream>
using namespace std;

int main(){

int arr[] = {1,2,3,4,5,6,7,8,9};

int size = 9;

int x,p;

cout << "Enter the number ";

cin >> x;

int k = search_position(arr, size, x);

cout << k << endl << endl;

system("pause 0");

return 0;

}