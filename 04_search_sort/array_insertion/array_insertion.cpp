#include <iostream>
using namespace std;

int main(){

int arr[]={1,4,7,2,4,12,432,22,31,22,};

int const size1 = 10;

int const size2 = 11;

int p,x; 

int n_arr[size2];

cout << "Enter the number you want to insert ";

cin >> x;

cout << "Enter the index for this element ";

cin >> p;

insertion(arr, n_arr, size1, x ,p);

for(int i=0; i < size2; i++){

  cout << n_arr[i] << " ";

  }

  cout << endl << endl;


system("pause 0");

return 0;

}