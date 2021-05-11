#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	<ctype.h>
#define		MAX_WORD_LEN	100
#define 	MAX_BUF		1000000

int main(){

	srand((unsigned) time(NULL));
	FILE *fp = fopen("dataset2.txt", "w");
	size_t i=0;
	size_t j=0;
	size_t code0, code1, code2;
	char word[MAX_WORD_LEN];
	char *ptr = word;

	while(i < MAX_BUF){
		while(j < MAX_WORD_LEN){

			code0 = rand();
			code1 = code0 % 100;
			code2 = code0 % 1000;
		
			if(isalpha(code1) || isalpha(code2)){
				if(isupper(code1) || islower(code1)){
					*ptr = code1;
					ptr++;
					j++;
				}
				else if(islower(code2)){
					*ptr = code2;
					ptr++;
					j++;
				}
			}
		}
		*ptr = '\0';
		fprintf(fp, "%s\n", word);
		i++;
		ptr = word;
		j = 0;
	}

	fclose(fp);
	return 0;
}
