#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main() {
	int big=0;
	int small=0;
  srand(time(0));
    for(int i = 0; i<1000000000; i++)
        if(1+rand()%100>50){
        	big++;
		}else{
			small++;
		}
  cout<<"big = "<<big<<"\n";
  cout<<"small = "<<small<<"\n";
  if(big>small){cout<<big-small;
  }else{
  	cout<<small-big;
  }
    return 0;
}
