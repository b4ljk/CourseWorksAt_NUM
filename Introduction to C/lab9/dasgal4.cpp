#include <iostream>
using namespace std;
int is_even(int);
void read(int arr[], int);
int max(int arr[], int);
int m1,m2;
int min5(int, int, int, int, int);
int minforreal(int, int);
int main() {
    cout<<min5(1,2,3,4,-6);

}
int min5(int a, int b, int c, int d, int e){
    int min;
   min=minforreal(min,a);
   min=minforreal(min,b);
   min=minforreal(min,c);
   min=minforreal(min,d);
   min=minforreal(min,e);
   return min;

    
}
int minforreal(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
// void read(int arr[], int n){
// 	int i;
// 	for(i=0;i<n;i++){
// 		cin>>arr[i];
// 	}}
// int max(int arr[], int n){
//     int max=0;
//     for(int i=0;i<n;i++){
//         if(max<arr[i])max=arr[i];
//     }
//     return max;
// }
	

