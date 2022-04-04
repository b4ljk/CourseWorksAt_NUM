#include <iostream>
using namespace std;
	int checker=0;
int join(int arr1[], int arr2[], int, int);
void read(int arr[], int);
void write(int arr[], int);
int main() {
	int n,m;
  cout<<"too oruul n m \n";
  cin>>n>>m;
  
  int arr1[n],arr2[m];
  read(arr1,n);
  read(arr2,m);
  cout<<join(arr1,arr2,n,m);
  return 0;
}

int join(int arr1[],int arr2[],int n,int m){
	int arr3[n+m];
	for(int i=0;i<n;i++){
		arr3[i]=arr1[i];
	}
	int j=0;
	for(int i=n;i<n+m;i++){
		arr3[i]=arr2[j];
		j++;
	}
	write(arr3,n+m);
	return (sizeof(arr3)/sizeof(*arr3));
}

void read(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}}
	
void write(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\n";
    }
    
}

	

