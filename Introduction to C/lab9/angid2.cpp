#include <iostream>
using namespace std;
int is_even(int);
void read(int arr, int);
int main() {
  
	cout << "array size oruul ";
	int n;
	cin >> n;
	int array[n];
	read(array[n],n);
}

void read(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
}
	

