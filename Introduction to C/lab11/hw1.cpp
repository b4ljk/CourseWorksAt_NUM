#include <iostream>
using namespace std;
struct student{
	char fname[20], lname[20],id[10];
	float golch;
};
typedef struct student student;
void read_students(student a[],int n){
	//n suragchiin too
	for(int i=0;i<n;i++){
		cout<<"oyutnii ner oruulna uu \n";
		cin>>a[i].fname;
		cout<<"oyutnii ovog oruulna uu \n";
		cin>>a[i].lname;
		cout<<"oyutnii id oruulna uu \n";
		cin>>a[i].id;
		cout<<"oyutnii golch oruulna uu \n";
		cin>>a[i].golch;
	}
}
void print_students(student a[],int n){
	//n suragchiin too
	for(int i=0;i<n;i++){
		
		cout<<"ner : "<<a[i].fname<<"\n";
		cout<<"ovog : "<<a[i].lname<<"\n";
		cout<<"id : "<<a[i].id<<"\n";
		cout<<"golch : "<<a[i].golch<<"\n";
		cout<<"--------------------------- \n";
	}
}
int search_by_fname(student a[],int n,char fname[]){
	for(int i=0;i<n;i++){
		
		if(a[i].fname==fname){
			return i;
		}
		
	}
}
int search_by_lname(student a[],int n,char lname[]){
	for(int i=0;i<n;i++){
		
		if(a[i].lname==lname){
			return i;
		}
		
	}
}
int search_by_id(student a[],int n,char id[]){
	for(int i=0;i<n;i++){
		
		if(a[i].id==id){
			return i;
		}
		
	}
}
int search_by_golch(student a[],int n,float golch){
	for(int i=0;i<n;i++){
		
		if(a[i].golch==golch){
			return i;
		}
		
	}
}
void sort_by_golch(student a[],int n){
	student temp;
	for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(a[i].golch<a[j].golch)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main() {
	int size;
	cout<<"suragchiin toogoo oruulna uu ? \n";
	cin>>size;
	student a[size];
  int n=size;
  read_students(a,n);
  print_students(a,n);
  sort_by_golch(a,n);
  print_students(a,n);
  
  return 0;
}

