#include <iostream>
using namespace std;
int is_even(int);
void read(int arr[], int);
int max(int arr[], int);
int m1,m2;
int main() {
  
	cout << "array size oruul ";
	int n,m;
	cin >> n;
	cin >> m;
	int array[n];
	int array1[m];
	
	read(array,n);
	read(array1,m);
    m1=max(array,n);
    m2=max(array1,n);
    if(m1==m2)cout<<"tentsuu ";
    if(m1<m2){
        cout<<"array 2 has got big ";    }else{
            cout<<"array 1 has got big ";
        }
}

void read(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}}
int max(int arr[], int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(max<arr[i])max=arr[i];
    }
    return max;
}
	

