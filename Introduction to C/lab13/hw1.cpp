
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

int main()
{
    int a[100];
    read(a, 5);
    int x,y;
   
    find(a,5,&x,&y);
    cout<< x<<y;
    return 0;
}
