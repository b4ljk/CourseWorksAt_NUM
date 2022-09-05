#include <stdio.h>

struct Student {
	char fname[20], lname[20], id[10];
	float gpa;
};

typedef struct Student Student;

void read(Student a[] , int n);
void print(Student a[] , int n);

/* a xvsnegted baigaa n oyutnii medeellig fname file -d bichne */
void student_write(Student a[], int n, char fname[]);

/*fname file -d baigaa oyutnii medeellig neg neg unshin a xvsnegted
xadgalaad xeden oyutnii medeelel unshij awsanaa butsaana.
*/
int student_read(Student a[], char fname[]);

int main ()
{
	Student a[100], b[100];
	int n, m;
	/* Oyutnii medeelliig garaas awna */
	printf("Oyutnii too: ");
	scanf("%d", &n);
	read(a, n);
	printf("\nOruulsan oyutnuudiin medeelel:\n");
	print(a, n);
	char name[] = "info.dat";
	student_write(a, n, name);
	m = student_read(b, name);
	printf("\nFile - aas unshsan oyutnuudiin medeelel:\n");
	print(b, m);
	return 0;
}

void read(Student a[] , int n){
	for(int i = 0; i < n; i++){
		printf("\n%d - r oyutnii medeelliig oruul\n", i + 1);
		printf("fname: ");
		scanf("%s", a[i].fname);
		printf("lname: ");
		scanf("%s", a[i].lname);
		printf("id: ");
		scanf("%s", a[i].id);
		printf("GPA: ");
		scanf("%f", &a[i].gpa);
	}
}

void print(Student a[] , int n){
	for(int i = 0; i < n; i++){
		printf("\n%d - r oyutnii medeelel\n", i + 1);
		printf("fname: %s ", a[i].fname);
		printf("lname: %s ", a[i].lname);
		printf("id: %s ", a[i].id);
		printf("GPA: %.2f\n", a[i].gpa);
	}
}

void student_write(Student a[], int n, char fname[]){
	FILE* fp = fopen(fname, "w");
	fwrite(a, sizeof(Student), n, fp);
	fclose(fp);
}

int student_read(Student a[], char fname[]){
	int cnt = 0;
	FILE* fp = fopen(fname, "r");
	while(!feof(fp)){
		fread(a, sizeof(Student), 1, fp);
		a++;
		cnt++;
	}
	fclose(fp);
	return cnt - 1;
}

