#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"S_swap.h"
#define		WORDLEN		100

void S_swap(char* str1, char* str2){
	char* tmp = malloc (sizeof(char) * (WORDLEN+1));
	strcpy(tmp, str2);
	strcpy(str2, str1);
	strcpy(str1, tmp);
	free(tmp);
}
