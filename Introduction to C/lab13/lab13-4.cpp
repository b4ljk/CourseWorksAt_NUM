/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void swap(int *a, int *b){
    int tempidiot;
    tempidiot=*a;
    *a=*b;
    *b=tempidiot;
}

int main()
{
    int x=1,y =2;
    swap(&x,&y);
    cout<<x<<y;
    return 0;
}
