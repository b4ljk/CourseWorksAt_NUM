
#include <iostream>

using namespace std;

int main()
{
    int n, sum =0;
    cout << "neg too oruulna uu ? ";
   cin >> n;
    for(int i=0; i<=n; i++){ //n too-g shalgana tegsh esehiig.
        if(i%2==0){
            sum=sum+i;
        }
    } cout << sum;
    return 0;
}
