#include <iostream>
#include <cmath>
using namespace std;
typedef struct {
	int dim;
	float dat[100];
} Vector;
int dot_product(Vector a, Vector b){
	int total=0;
	for(int i=1;i<a.dim;i++){
		total+=a.dat[i]*b.dat[i];
	}
	return total;
}
Vector scalar_mult(Vector a, float t){
	for(int i=1;i<a.dim;i++){
		a.dat[i]=a.dat[i]*t;
	}

	return a;
}

int len(Vector a){
	int len;
	len=dot_product(a,a);
	len=sqrt(len);
	return len;
}
int main(){
	cout<<"idiot";
	return 0;
}
