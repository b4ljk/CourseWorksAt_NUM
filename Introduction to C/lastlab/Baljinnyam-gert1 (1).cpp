#include <stdio.h>
#include <stdlib.h>
#define N 100

int *get_array_from_file(char fname[]);

int main(){
	char str[] = "array";
	int* a = get_array_from_file(str);
	
	printf("fname file-iin husnegtiin hemjee: %d\n", a[0]);
	printf("\nfname file-iin husnegtiin elementuud: ");
	for(int i = 1; i <= a[0]; i++)
		printf("%d ", a[i]);
		
	free(a);
	return 0;
}

int *get_array_from_file(char fname[]){
	int* p;
	p = (int*)malloc(sizeof(int)*N);
	if(p == NULL){	
		printf("Sanax oi xvrsengvi!\n");
		exit(1);
	}
	int i = 0;
	FILE *fp = fopen(fname, "r");
	while(!feof(fp)){
		int a = 0;
		fscanf(fp, "%d", &a);
		p[i++] = a;
	}
	fclose(fp);
	return p;
}

