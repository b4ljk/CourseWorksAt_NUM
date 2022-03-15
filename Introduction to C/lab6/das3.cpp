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
    cout << "n uguh utga";
    cin >> n;
    cout << "m uguh utga";
    cin >> m;
    int a[n],b[m],c[n+m];
    for(int i = 0; i < n ; i++){
        cout << "enntern num";
        cin >> a[i];
    }
    for(int i = 0; i < m ; i++){
        cout << "enntern num";
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
    for(int i=0;i<n+m;i++){
        cout<<c[i];
    }
    return 0;
}
