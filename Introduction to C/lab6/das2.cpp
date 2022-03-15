/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "husnegtiin hemjeeg oruulna uu ? \n";
    cin >> n;
    int husnegt[n];
    for(int i =0 ; i<n;i++){
        cout<< "toogoo oruul; \n";
        cin >> husnegt[i];
    }
    for(int i = n-1; i>=0; i--){
        cout << husnegt[i] << "\n";
    }
   

    return 0;
}
