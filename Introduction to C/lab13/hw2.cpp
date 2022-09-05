
#include <iostream>

using namespace std;
void read(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}}
	


void find(int a[], int n, int *min, int *max){
    *min=a[0];
    *max=0;
    for(int i=0;i<n;i++){
    	if(a[i]<*min){
    		*min=a[i];
		}
		if(a[i]>*max){
    		*max=a[i];
		}
	}
}

int *search(int a[], int value, int size){
	for(int i=0;i<size;i++){
		if(a[i]==value){
			return &a[i];
		}
	}
	return 0;
}

int main()
{
    int a[100];
    read(a, 5);
    int *p;
    p=search(a,3,5);
	if(p == 0){
		cout<<"oldsongui";
	}else{
		cout<<p<<" bairshild oldloo";
	}

    return 0;
}
