/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct {
    int d, m, y;
    
} Date;

Date read(){
    Date date;
    cout<<"jil sar udur oruulna uu ";
    cin>>date.y>>date.m>>date.d;
    return date;
}
void print(Date date){
    string month="/",day="/";
    if(date.m<10){
        month="/0";
    }
    if(date.d<10){
        day="/0";
    }
    cout<<date.y<<month<<date.m<<day<<date.d<<"\n";
    // printf("%d onii %0.2d sariin %0.2d udur",date.y, date.m,date.d);
}
int lessone(Date a, Date b){
    if(a.y==b.y){
        if(a.m==b.m){
            if(a.d<b.d){
                return 1;
            }else return 0;
        }else if(a.m<b.m){
            return 1;
        }else return 0;
    }else if(a.y<b.y){
        return 1;
    }else{
        return 0;
    }
}
void sortDate(Date date[], int n){
    Date temp;
	for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(lessone(date[i],date[j])==0)
			{
				temp=date[i];
				date[i]=date[j];
				date[j]=temp;
			}
		}
	}
}
int main()
{   int n;
    
    cout<<"array hemjee oruulna uu? \n";
    cin>>n;
    Date mydate[n];
    for(int i=0;i<n;i++){
        mydate[i]=read();
        
    }
    sortDate(mydate,n);
    for(int i=0;i<n;i++){
       print(mydate[i]);
      
        
    }
    
    return 0;
}
