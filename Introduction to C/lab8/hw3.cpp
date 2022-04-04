#include <iostream>
using namespace std;


int main() {
		string a,b;
		cout << "uguulber oruulna uu ? ";
		getline (cin, a);
		cout<<"haih ugee oruulna uu ?";
		cin>>b;
		int k=0;
		int urt=0;
		bool found=false;
		for(int i=0;i<a.length();i++){
			urt++;
			
			if(a[i]==b[k]){
				k++;
				if(b.length()==k && urt==k){
					cout<<"adil ug "<<i-k+1<<" index deer oldloo .";
					return 0;
				}
			}else{
				k=0;
			}
			if(a[i]==' '){
				urt=0;
			}
			
		}
		cout<<"-1";
		return 0;
		
		//LYM
}


