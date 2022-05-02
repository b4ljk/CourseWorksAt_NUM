/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct Triangle{
    int a,b,c;
};
void read(struct Triangle *p){
    cin>>p->a>>p->b>>p->c;
    
}

int main()
{
    struct Triangle g;
    read(&g);
    cout<<g.a;
    cout<<g.b;
    cout<<g.c;
    
}
