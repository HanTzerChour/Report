#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/time.h>
#define		MAXLEN		1000000
#define		WORDLEN		100

int main(){

	FILE *fp = fopen("dataset2.txt", "r");
	FILE *fq = fopen("insertion_sorted_word.txt", "w");
	char* buf[MAXLEN];
	int n = 0;
	int i, j;
	unsigned long diff;
	struct timeval start;
	struct timeval end;

	while(n < MAXLEN){
		buf[n] = malloc((sizeof(char) * (WORDLEN + 1)));
		fscanf(fp, "%s", buf[n]);
		n++;
	}
	
	gettimeofday(&start, NULL);
	for(i = 1; i < MAXLEN; i++){
		char *current = strdup(buf[i]);
		j = i - 1;
		while((j>-1) && (strcmp(buf[j] , current) > 0)){
			strcpy(buf[j+1] , buf[j]);
			j--;
		}
		strcpy(buf[j+1] , current);
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
