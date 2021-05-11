#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/time.h>
#define		MAXLEN		1000000

int main(){

	FILE *fp = fopen("dataset1.txt", "r");
	FILE *fq = fopen("bubble_sorted_num.txt", "w");
	int i, j;
	int buf[MAXLEN];
	int n = 0;
	unsigned long diff;
	struct timeval start;
	struct timeval end;

	while(n < MAXLEN){
		fscanf(fp, "%d",&buf[n]);
		n++;
	}
	
	gettimeofday(&start, NULL);
	for(i = 0; i<MAXLEN; i++){
		for(j = 0; j<MAXLEN-i-1; j++){
			if(buf[j] > buf[j+1]){
				int tmp = buf[j+1];
				buf[j+1] = buf[j];
				buf[j] = tmp;
			}	
		}

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
