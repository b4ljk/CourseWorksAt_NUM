/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int ecount(string arr);
int main()
{
    string str;
    cin>>str;
    cout<<ecount(str);
    return 0;
}
int ecount(string arr){
    int total=0;
    int n=arr.length();
    for(int i=0;i<n;i++){
        if(arr[i]=='A' || arr[i]=='E' || arr[i]=='I' || arr[i]=='O' || arr[i]=='U'){
            total++;
        }
        if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
            total++;
        }
    }
    return total;
}