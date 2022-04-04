#include <iostream>
using namespace std;
	int checker=0;
int func1(int);
int main() {
	int n;
  cout << "Hello World!";
  cout<<"too oruul \n";
  cin>>n;
  for(int i=1;i<n;i++){
  	if(i%func1(i)==0){
  		cout<<i<<"\n";
	  }
  }
  return 0;
}

int func1(int n){
	int total = 0;
	while(n>0){
		total=total+n%10;
		n/=10;
	}
	return total;
}
