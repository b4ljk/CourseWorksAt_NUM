
#include <iostream>

using namespace std;

struct rational{
	int d,n;
};
typedef rational rational;
void simplify(rational *a){
	int min;
	if(a->d>a->n){
		min=a->n;
	}else{
		min=a->d;
	}
	for(int i=min;i!=0;i--){
		if(a->d%i==0 && a->n%i==0){
			a->d=a->d/i;
			a->n=a->n/i;
		}
	}
}
rational add(const rational *a, const rational *b){
	rational total;
	total.d=a->d+b->d;
	total.n=a->n+b->n;
	simplify(&total);
	return total;
	
}
rational sub(const rational *a, const rational *b){
	rational total;
	total.d=a->d-b->d;
	total.n=a->n-b->n;
	simplify(&total);
	return total;
}
rational mult(const rational *a, const rational *b){
	rational total;
	total.d=a->d+b->d;
	total.n=a->n+b->n;
	simplify(&total);
	return total;
}
rational divi(const rational *a, const rational *b){
	rational total;
	
	total.d=a->d*b->n;
	total.n=a->n*b->d;
	simplify(&total);
	return total;
}

void read(rational *a){
	cin>>a->d;
	cin>>a->n;
}
void print(rational *a){
	cout<<a->d<<"/"<<a->n;
}
int main()
{
    struct rational a,divi1,b;
    read(&a);
    read(&b);
    divi1=divi(&a,&b);
    simplify(&divi1);
	print(&divi1);
    return 0;
}
