/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int check(string name,string pass){
    string userName[4]={"bat","dorj","bold","tsetsgee"};
    string password[4]={"123456","password","pass247","justinbeaber"};
    for(int i=0;i<4;i++){
        if(userName[i]==name){
            if(password[i]==pass)return 1;
        }
        
    }
    return 0;
}
int main()
{
    cout<<"username oruulna uu ? \n";
    string username,password;
    cin>>username;
    cout<<"password oruulna uu ? \n";
    cin>>password;
    cout<<check(username,password);

    return 0;
}
