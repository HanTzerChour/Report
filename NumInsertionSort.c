#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/time.h>
#define		MAXLEN		1000000

int main(){

	FILE *fp = fopen("dataset1.txt", "r");
	FILE *fq = fopen("insertion_sorted_num.txt", "w");
	int buf[MAXLEN];
	int n = 0;
	int i, j;
	unsigned long diff;
	struct timeval start;
	struct timeval end;

	while(n < MAXLEN){
		fscanf(fp, "%d", &buf[n]);
		n++;
	}
	
	gettimeofday(&start, NULL);
	for(i = 1; i < MAXLEN; i++){
		int current = buf[i];
		j = i - 1;
		while((j>-1) && (buf[j] > current)){
			buf[j+1] = buf[j];
			j--;
		}
		buf[j+1] = current;
	}
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	n = 0;

	while(n < MAXLEN){
		fprintf(fq, "%d\n", buf[n]);
		n++;
	}

	printf("%lu\n", diff);
	fclose(fp);
	fclose(fq);

	return 0;
}
