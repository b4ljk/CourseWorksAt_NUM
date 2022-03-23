/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{   
    int n,m,total=0,max=0,pr[10],k=0;
    cout << "enter arr size ";
    cin >>n;
    cout << "enter arr size ";
    cin >> m;
    int all[n][m];
    for(int i =0; i<n;i++){
        for(int j =0;j<m;j++){
           cin >>all[i][j];
        }
    }
    for(int i =0; i<n;i++){
        for(int j =0;j<m;j++){
           if(all[i][j]%2==0){
               total++;
           }
        }
        if(total>=max){
           
            if(max==total){
                k++;
            }
             pr[k]=i;
            max=total;
        }
        total=0;
        
    }
    for(int i =0;i<=k;i++){
        cout<<"big is "<<pr[i]<<"\n";
    }
    
}
