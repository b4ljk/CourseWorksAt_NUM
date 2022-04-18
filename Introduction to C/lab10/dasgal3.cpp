/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int ecount(int n);
int arr[100000];
int main()
{
    int n;
    cout << "too oruul \n";
    cin >> n;
    arr[n];
    int huvaagch=ecount(n);
    cout<<huvaagch<<"\n";
    for(int i=0; i<huvaagch;i++){
        cout<<arr[i]<<"\n";
    }
    
    
}
int ecount(int n){
    int total=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
           
            arr[total]=i;
             total++;
        }
    }
   
    return total;
}