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
	
void write(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\n";
    }
    
}
int modul(int num){
    if(num<0)num=num*-1;
    return num;
}
int sum(int arr[], int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    return total;
}
int avg(int arr[], int n){
    int avg=0;
    for(int i=0;i<n;i++){
        avg+=arr[i];
    }
    avg=avg/n;
    return avg;
}
int pdct(int arr[], int n){
    int product=arr[0];
    for(int i=1;i<n;i++){
        product=product*arr[i];
    }
    return product;
}
int main()
{
    int a[100],n,b[100];
    cout<<"too oruul \n";
    cin>>n;
    read(a,n);
    cout<<"tanii oruulsan daraalal \n";
    write(a,n);
    
    int mu,i;
    mu=avg(a,n);
    cout<<"mu giin utga ni : "<<mu;
    for(i=0;i<n;i++){
        b[i]=modul(a[i]-mu);
    }
    
    int alpha;
    alpha=pdct(b,n);
    cout<<"\nalpha utga ni :"<< alpha;
    return 0;
}
