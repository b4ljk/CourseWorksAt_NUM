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
    int aurt,burt,curt;
    cout<<"a ug oruul \n";
    cin>>a;
    cout<<"b ug oruul \n";
    cin>>b;
    aurt=a.length();
    burt=b.length();
    curt=aurt+burt;
    string c[curt];
    for(int i=0;i<aurt;i++){
        c[i]=a[i];
    }
    int j=0;
    for(int i=aurt;i<curt;i++){
        c[i]=b[j];
        j++;
    }
    for(int i=0;i<curt;i++){
        cout<<c[i];
    }
    
}
