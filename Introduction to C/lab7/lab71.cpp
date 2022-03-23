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
    cout << "enter num ";
    cin >>n;
    int all[n];
    for(int i =0; i<n;i++){
        cout << "enter height";
        cin >> all[i];
        total +=all[i];
    }
    total=total/n; //dundaj bolno
    for(int i=0; i<n; i++){
        if(all[i]>total){
            aboveavg++;
        }
    }
    cout<< aboveavg;
}
