/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n,m,x;
    cout << "n oroh utgiig ogno uu ?  \n";
    cin >> n;
    cout << "m oroh utgiig ogno uu ?  \n";
    cin >> m;
    bool usuh = true, buurah = true;
    cout << m;
    int husnegt[n][m];
    for(int i =0 ; i<n;i++){
        for(int j = 0 ; j < m ; j++){
            cout<< "toogoo oruul; \n";
            cin >> husnegt[i][j];
        }
    }
    cout << "x toogoo haruulna uu ? ";
    cin >> x;
    for(int i =0 ; i<n; i++){
        for(int j =0;j<n;j++){
            if(husnegt[i][j]==x){
                cout << i << "murnii " << j << " dgr elemented oldloo . \n";
            }
        }
    }

    return 0;
}
