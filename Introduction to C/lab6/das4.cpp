/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n,x;
    cout << "husnegtiin hemjeeg oruulna uu ? \n";
    cin >> n;
    int husnegt[n];
    for(int i =0 ; i<n;i++){
        cout<< "toogoo oruul; \n";
        cin >> husnegt[i];
    }
    cout << "x-d hadgalah toogoo oruulna uu ? ";
    cin >> x;
   for(int i = 0 ; i < n; i++){
       if(husnegt[i]==x){
           cout << "oldson bairlal = " << i<< "\n";
       }
   }
   

    return 0;
}
