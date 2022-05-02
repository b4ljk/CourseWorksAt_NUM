/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void read(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}}
void find(int a[], int n, int *addr, int *addr1){
    *addr1=0;
    *addr=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            *addr=*addr+1;
            
        }else{
            *addr1=*addr1+1;
        }
    }
}

int main()
{
    int a[100];
    read(a, 5);
    int x,y;
   
    find(a,5,&x,&y);
    cout<<"tegsh toonuudiin too ni "<<x<<"\n";
    cout<<"sondgoi toonuudin too ni "<<y;
    return 0;
}
