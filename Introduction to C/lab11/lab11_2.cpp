/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
struct point {
    double x,y;
    
};
double distance(point a, point b){
    double d;
    d=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    return d;
}
int main()
{   double zai;
    struct point a,b;
    cout<<"point 1 : \n";
    cin>>a.x>>a.y;
    cout<<"point 2 : \n";
    cin>>b.x>>b.y;
    zai=distance(a,b);
    cout<<zai;
    return 0;
}
