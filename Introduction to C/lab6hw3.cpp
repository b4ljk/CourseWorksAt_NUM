/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
 

int main()
{ 	
int a,b,c;
cout<<"ortsnii toog oruul \n";
cin>>a;
cout<<"davhriin toog oruul \n";
cin>>b;
cout<<"neg davhart baih ailiin toog oruul \n";
cin>>c;
cout<<"\n";
int ail[a][b][c];
int dugaar=1;
for(int i=1;i<=a;i++){
	for(int j=1;j<=b;j++){
		for(int k=1;k<=c;k++){
			ail[i][j][k]=dugaar;
			dugaar++;
		}
	}
}
for(int i=1;i<=a;i++){
	for(int j=1;j<=b;j++){
		for(int k=1;k<=c;k++){
			cout<<i<<" orts "<<j<<" davhar "<<ail[i][j][k]<<" toot \n";
		}
	}
}


	}
	


