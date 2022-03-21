#include <iostream>
using namespace std;

int main() {
  int n,m,k,c;
  cout << "array hemjee oruulna uu \n";
  cin >> n;
  
  int arr[n][n];
for(int i=0;i<n;i++){
	k=i+1;
	c=n-1;
  	for(int j=0;j<n;j++){
  		if(k>n){
  			
  			arr[i][j]=c;
  			c--;
		  }else{
		  	arr[i][j]=k;
  		k++;
		  }
  		
	  }
	  k=0;
	  c=0;
  }
for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++){
  		cout << arr[i][j]<<" ";
  	
	  }cout << "\n";
  }
  return 0;
}
