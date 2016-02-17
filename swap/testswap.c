/*
Intercambiar dos variables sin importar el tipo de datos
mismo tipo entre si
decimos el tipo
Programador: cams93
*/

#include <stdio.h>
#include <strings.h>
#include "swap.h"

int testint(void);
int testintG(void);
int testArray(void);
int testStrings(void);

int main(){
	testint();
	testintG();
	testArray();
	testStrings();
	return 0;
}

int testint(){
	int a=4;
	int b=5;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

int testintG(){
	int a=4;
	int b=5;
	printf("a = %d, b = %d\n", a, b);
	swapgeneric((void *)&a, (void *)&b, sizeof(int));
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

int testArray(){
	int a[]={2, 3, 4, 5};
	int b[]={1, 1, 1, 1};
	int i;
	for(i=0; i<4; i++){
		printf("a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
	}
	swapgeneric((void *)a, (void *)b, 4*sizeof(int));
	for(i=0; i<4; i++){
		printf("a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
	}
	return 0;
}

int testStrings(){
	char *juan = strdup("Juan");
	char *maria = strdup("Maria");
	swapgeneric((void *) &juan, (void *) &maria, sizeof(char *));
	printf("Juan es %s, Maria es %s\n", juan, maria);
	return 0;
}