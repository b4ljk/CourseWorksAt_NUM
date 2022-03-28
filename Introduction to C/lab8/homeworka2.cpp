#include <iostream>
using namespace std;


int main() {
		string a;
		int total=0;
		int max=0;
		int max_ug=0,ug_urt=0;
		cout << "uguulber oruulna uu ? ";
		getline (cin, a);
		string myarr[a.length()];
		for(int i=0;i<a.length();){
			for(;a[i]!=' ' && i<a.length() ;i++){
				if(a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U' || a[i]=='a' || a[i]=='e' || a[i]=='i'|| a[i]=='o' || a[i]=='u'){
					total++;
					
				}
				ug_urt++;
			}
		
		
			if(max<total){
				max_ug=ug_urt;
				max=total;
				int k=0,j=0;
				j=i;
				
				while(true){
					
					myarr[k]=a[j];
					j=j-1;
					if(a[j]==' ' || j==-1){
						break;
					}
					k++;
				}
				k=0;
			}
				i++;
			total=0;
			ug_urt=0;
		}

		int i=max_ug;
		while(i>=0){
			cout<<myarr[i];
			i--;
		}
		return 0;
		//hamgiin hachin gaitai bodlogo baiv.
}


