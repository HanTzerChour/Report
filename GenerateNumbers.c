#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define		MAXBUF		1000000

int main(){

	srand((unsigned) time(NULL));
	size_t n=0;
	FILE *fp = fopen("dataset1.txt", "w");
	
	size_t num[MAXBUF];
	while(n<MAXBUF){
		num[n]= rand();
		fprintf(fp, "%d\n" ,num[n]);
		n++;
	}	

	fclose(fp);
	
	return 0;
}
