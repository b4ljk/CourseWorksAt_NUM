#include <iostream>
using namespace std;

int main() {
		string a;
		int total;
		cout << "uguulber oruulna uu ? ";
		getline (cin, a);
		for(int i=0;i<a.length();i++){
			if(a[i]==' '){
				total++;
			}
		}
		total++;
		cout << "Niit "<<total<<" ugtei uguulber baina .";
}		
