/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string a;
    cout<<" gimme sum string ";
    cin>>a;
    int total =0;
    for(int i=0; i<a.length();i++){
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' ){
            total++;
        }
    }
    cout<<total;
    return 0;
}
