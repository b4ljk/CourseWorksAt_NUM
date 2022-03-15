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
    bool usuh = true, buurah = true;
    
    int husnegt[n];
    for(int i =0 ; i<n;i++){
        cout<< "toogoo oruul; \n";
        cin >> husnegt[i];
    }
   for(int i =1 ; i<n ; i++){
       if(husnegt[i-1]>husnegt[i]){
           usuh = false;
       }
       if(husnegt[i-1]<husnegt[i]){
           buurah = false;
       }
       //cout<<i;
   }
   if(usuh==true){
       cout << "Өсөх эрэмбэтэй тоо байна . \n";
       return 0;
   }
   if(buurah==true){
       cout << "buurdag too bna ho \n";
       return 0;
   }
   cout<<"erembegui baina \n";

    return 0;
}
