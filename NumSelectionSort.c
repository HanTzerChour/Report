#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/time.h>
#define		MAXLEN		1000000

int main(){

	FILE *fp = fopen("dataset1.txt", "r");
	FILE *fq = fopen("selection_sorted_num.txt", "w");
	int n = 0;
	int i, j, idx;
	int buf[MAXLEN];
	unsigned long diff;
	struct timeval start;
	struct timeval end;

	while(n < MAXLEN){
		fscanf(fp, "%d", &buf[n]);
		n++;
	}

	gettimeofday(&start, NULL);
	for(i=0; i<MAXLEN; i++){
		idx = i;
		for(j=i+1; j<MAXLEN; j++){
			if(buf[idx] > buf[j]){
				idx = j;
			}
		}
		int tmp = buf[i];
		buf[i] = buf[idx];
		buf[idx] = tmp;
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
