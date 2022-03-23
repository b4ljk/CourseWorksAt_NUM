/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{   
    int n,total=0,aboveavg=0;
    cout << "enter arr size ";
    cin >>n;
    int all[n];
    for(int i =0; i<n;i++){
        cout << "enter num";
        cin >> all[i];
    }
    for(int i =0; i<n;i++){
        if(all[i]!=all[n-1-i]){
            cout<<"not a palindrome aye ";
            return 0;
        }
    }cout << " palindrome bna";
}
