#include <iostream>
using namespace std;
int is_even(int);
void read(int, int);
int main() {
  
	int n,even;
	cout << "too oruulna uu ?";
	cin >> n;
  for(int i=0; i<n;i++){
  	if(is_even(i)==0){
  		cout<<i<<"\n";
	  }
  }
}

int is_even(int n){
	if(n%2==0){
		return 1;
	}else{
		return 0;
	}
	
}
