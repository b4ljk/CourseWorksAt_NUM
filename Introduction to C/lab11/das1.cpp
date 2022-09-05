/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
struct Triangle {
    double a,b,c;
    
};
double tomyo(double a,double b,double c){
    double p,s;
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}
int main()
{   double s1,s2;
    struct Triangle t1,t2;
    cout<<"guvaljin 1 : \n";
    cin>>t1.a>>t1.b>>t1.c;
    cout<<"guvaljin 2 : \n";
    cin>>t2.a>>t2.b>>t2.c;
    s1=tomyo(t1.a,t1.b,t1.c);
    s2=tomyo(t2.a,t2.b,t2.c);
    if(s1>s2){cout<<s1;}else{cout<<s2;};
    return 0;
}
