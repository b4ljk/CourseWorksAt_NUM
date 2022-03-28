/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string a,b;
    cout<<" gimme sum word ";
    cin>>a;
    cout<<" gimme sum word ";
    cin>>b;
    int total =0;
    if(a.length()!=b.length()){
        cout<<" uur ug";
        return 0;
    }
    for(int i=0; i<a.length();i++){
        if(a[i]!=b[i]){
            cout<<" uur ug";
        return 0;
        }
    }
    cout<<"adil ug bna";
    return 0;
}
