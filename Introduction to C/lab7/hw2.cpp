#include <iostream>
using namespace std;

int main() {
  int n,m;
  cout << "array hemjee oruulna uu \n";
  cin >> n;
  n++;
  cout << "array hemjee oruulna uu \n";
  cin >> m;
  int arr[n][m];
for(int i=0;i<=n;i++){
  	for(int j =0;j<m;j++){
  		arr[i][j]=i;
	  }
  }
for(int i =1;i<=n;i++){
  	for(int j =0;j<m;j++){
  		cout << arr[i][j]<<" ";
  	
	  }cout << "\n";
  }
  return 0;
}
