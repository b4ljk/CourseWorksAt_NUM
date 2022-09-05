/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int row[100];
int col[100];
void findmin(int a[][100], int n, int m, int row[], int col[]){
    
    for(int i=0;i<n;i++){
        int minrow=1000,mincol=1000;
        for(int j=0;j<m;j++){
            if(a[i][j]<minrow)minrow=a[i][j];
            if(a[j][i]<mincol)mincol=a[j][i];
        }
        row[i]=minrow;
        col[i]=mincol;
    }
}
int main()
{
    int x[3][100] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
    findmin(x,3,4,row,col);
    for(int i=0;i<4;i++){
        cout<<">>>mur>>>"<<row[i]<<"\n";
        cout<<">>>bagana>>>"<<col[i]<<"\n";
    }
    return 0;
}
