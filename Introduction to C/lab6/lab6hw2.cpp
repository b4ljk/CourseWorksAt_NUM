/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
 

int main()
{ 	int n;
	cout<<"husnegtiin hemjee \t";
	cin>>n;
   
    int arr[n][n];
    for(int i=0; i<n;i++){
    	for(int j=0; j<n;j++){
    		cout << "oruulah utga oruul \t";
    		cin >> arr[i][j];
		}
	}
	
	//mur
	int mur=0;
	for(int i=0; i<n;i++){
		for(int j=0;j<n;j++){
			mur+=arr[i][j];
		}
		cout<<i+1<<"muriin niilber bol "<<mur<<"\n";
		mur=0;
	}
	//bagana
	for(int i=0; i<n;i++){
		for(int j=0;j<n;j++){
			mur+=arr[j][i];
		}
		cout<<i+1<<"baganiin niilber bol "<<mur<<"\n";
		mur=0;
	}
	
	//diagonal zuun
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			if(i==j){
				mur+=arr[i][j];
			}
		}
	}
	cout<< "zuun diagonal ni "<<mur <<"\n";
	mur=0;
	//daigonal baruun
	int j=n-1;
	for(int i=0;i<n;i++){
		mur+=arr[i][j-i];
	
	}
 	cout<< "baruun diagonal ni "<<mur;
    return 0;
	}
	


