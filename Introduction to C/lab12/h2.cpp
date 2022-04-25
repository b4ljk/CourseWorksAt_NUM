#include <iostream>
#include <cmath>
using namespace std;
struct point {
    int x,y;
    
};
typedef struct point point;
point readpoint(){
	point zetta;
	cin>>zetta.x>>zetta.y;
	return zetta;	
}


double distancex(point a, point b){
    double d;
    
    d=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
  
    return d;
    
}

struct Triangle {
    point a,b,c;
    
};
typedef struct Triangle Triangle;

double tomyo(point x,point y,point z){
	double a,b,c;
	a=distancex(x,y);
	b=distancex(x,z);
	c=distancex(y,z);

    double p,s;
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    
    return s;
}
int main() {
  	Triangle t1;
    cout<<"guvaljin hemjee oruul point 1 point 2 : \n";
    point a,b,c;
    Triangle Triangle1;
    a=readpoint();
    b=readpoint();
    c=readpoint();
    Triangle1.a=a;
    Triangle1.b=b;
    Triangle1.c=c;
    cout<<tomyo(Triangle1.a,Triangle1.b,Triangle1.c);
  return 0;
}
