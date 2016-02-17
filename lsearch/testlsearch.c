#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lsearch.h"

int testIntA(void);
int testCharA(void);
int testStringA(void);

int main(){
	testIntA();
	testCharA();
	testStringA();
	return 0;
}

int testIntA(void){
	int a[] = {2, 3, 4, 5};
	if(lsearch(4, a, 4) > 0)
		printf("encontrado\n");
	else
		printf("no encontrado\n");
}

int testCharA(void){
	char c = 'z';
	char *st = strdup("Perez");
	char *r;
	r = (char *)lsearchgeneric((void *)&c, (void *)st, sizeof(char), strlen(st), cmpchar);
	if(r != 0){
		printf("%c, %p\n", *r, r);
	}
	return 0;
}

int testStringA(void){
	char *c = strdup("zol");
	char **st = (char **)malloc(sizeof(char *)*3);
	st[0] = strdup("fjf");
	st[1] = strdup("zol");
	st[2] = strdup("kjd");
	char **r;
	r = (char **)lsearchgeneric((void *)c, (void *)st, sizeof(char *), 3, cmpstring);
	if(r != 0){
		printf("%s, %p\n", *r, r);
	}
}

//string dentro de un arreglo de string - cmpstring regresa direccion donde esta el string en el arreglo de strings 