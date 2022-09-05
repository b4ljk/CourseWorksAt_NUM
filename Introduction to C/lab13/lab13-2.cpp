/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void even(int n, int *p){
    if(n%2==0){
        *p=1;
    }else{
        *p=0;
    }
}

int main()
{
    int x, n;
    cin>>n;
    even(n, &x);
    if(x==1){
        cout<<"tegsh";
        
    }else{
        cout<<"not tesgsh";
    }

    return 0;
}
