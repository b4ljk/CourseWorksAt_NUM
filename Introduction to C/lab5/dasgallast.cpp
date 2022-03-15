
#include <iostream>

using namespace std;

int main()
{
    int x,sum=0;
    cout << "too oruulna uu ?";
    cin >> x;
    for(int i =0; i<x;i++){
        sum=sum+x%10;
        x=x/10;
    }
    cout << sum;
    return 0;
}
