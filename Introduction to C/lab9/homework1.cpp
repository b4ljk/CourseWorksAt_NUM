#include <iostream>
using namespace std;
	int checker=0;
int isPalindrome(int);
int main() {
	int n;
  cout << "Hello World!";
  cout<<"too oruul \n";
  cin>>n;
  cout<<isPalindrome(n);
  return 0;
}

int isPalindrome(int a){
	while(checker<a){
	checker=checker*10+a%10;
	a=a/10;
	}
	return a==checker || a==checker/10;
	
}
