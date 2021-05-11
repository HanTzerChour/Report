#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/time.h>
#include	<string.h>
#include	"S_swap.h"
#define		MAXLEN		1000000
#define		WORDLEN		100

int main(){

	FILE *fp = fopen("dataset2.txt", "r");
	FILE *fq = fopen("bubble_sorted_word.txt", "w");
	int i, j;
	char *buf[MAXLEN];
	int n = 0;
	unsigned long diff;
	struct timeval start;
	struct timeval end;

	while(n < MAXLEN){
		buf[n] = malloc (sizeof(char) * (WORDLEN+1));
		fscanf(fp, "%s", buf[n]);
		n++;
	}
	
	gettimeofday(&start, NULL);
	for(i = 0; i<MAXLEN; i++){
		for(j = 0; j<MAXLEN-i-1; j++){
			if(strcmp(buf[j], buf[j+1]) > 0){
				S_swap(buf[j], buf[j+1]);
			}	
		}

	}
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

	n = 0;
	while(n < MAXLEN){
		fprintf(fq, "%s\n", buf[n]);
		n++;
	}

	printf("%lu\n", diff);

	fclose(fp);
	fclose(fq);

	return 0;
}
