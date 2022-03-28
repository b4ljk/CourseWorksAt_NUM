/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    char s[10]="hello";
    char s2[20]="muis-iinhaan";
    for(int i=0;i<5;i++){
        s2[i]=s[i];
    }
    for(int i=5;i<19;i++){
        s2[i]=' ';
    }
    cout<<s2;
}
