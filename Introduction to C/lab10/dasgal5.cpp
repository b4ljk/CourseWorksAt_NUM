/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void isValid(string password);
bool urt=true,big=false,nums=false,chars=false;
int main()
{
    string n;
    cout << "password oruul \n";
    cin >> n;
    isValid(n);
    if(urt==false){
        cout<<"urt 6 aas ih baih yostoi \n";
    }
    if(big==false){
        cout<<"ydaj neg tom useg baih yostoi \n";
    }
    if(nums==false){
        cout<<"ydaj 3n too baih ystoi \n";
    }
    if(chars==false){
        cout<<"tusgai temdegt baih ystoi";
    }
    if(urt==true&&big==true&&nums==true&&chars==true)cout<<"password is valid ";
}

void isValid(string password){
    int totalnums=0;
    if(password.length()<6)urt=false;
    for(int i=0; i<password.length();i++){
        if(64<int(password[i])&&int(password[i])<91)big=true;
        if(47<int(password[i])&&int(password[i])<58)totalnums++;
        if(32<int(password[i])&&int(password[i])<47)chars=true;
    }
    if(totalnums>=3)nums=true;
}
