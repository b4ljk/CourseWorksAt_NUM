/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
 

int main()
{
    int n, m;
    bool isdup;
    cout << "n uguh utga \n";
    cin >> n;
    cout << "m uguh utga \n";
    cin >> m;
    int a[n],b[m],c[n+m];
    for(int i = 0; i < n ; i++){
        cout << "enntern num \t";
        cin >> a[i];
    }
    for(int i = 0; i < m ; i++){
        cout << "enntern num \t";
        cin >> b[i];
    }
	 for(int i = 0; i<n; i++){
        c[i]=a[i];
    }
    int j = 0;
    for(int i=n; i<n+m;i++){
        c[i]=b[j];
        j++;
    }
	int k=0;
    int garalt[n+m];
    for(int i=0; i<n+m;i++){
    	isdup = true;
    	for(int j=0;j<=i;j++){
    		if(c[i]==garalt[j]){
    			isdup=false;
			}
		}
		if(isdup==true){
			garalt[k]=c[i];
			k++;
		}


	
		}
		
		
		//garalt
    for(int i=0;i<k;i++){
    	cout << garalt[i]<<"\n";
	}
 
    return 0;
	}
	


