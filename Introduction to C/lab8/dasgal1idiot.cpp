/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string ovog,ner,ungu,hobby,freetime;
    int bday,month,year;
    cout<<"tanii ovog ? \n";
    cin>>ovog;
    cout<<"tanii ner ? \n";
    cin>>ner;
    cout<<"tanii tursun on sar udur ? \n";
    cin>>year>>month>>bday;
    cout<<"tanii ungu ? \n";
    cin>>ungu;
    cout<<"tanii hobby ? \n";
    cin>>hobby;
    cout<<"ta chuluut tsagaaraa yu hiidg we ? \n";
    cin>>freetime;
    int nas;
    nas=2022-year;
    cout<< ovog<< " ovogtoi "<< ner << " ni "<<year<<"/"<<month<<"/"<<bday<<" udur tusun ";
    cout<<"odoo "<< nas << " nastai "<< "tuunii durtai ungu bol "<<ungu<<" Ter chuluut tsagaaraa ";
    cout<<freetime<<" hiideg. "<<" Tuunii hobby bol "<<hobby;

    return 0;
}
