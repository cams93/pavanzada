/*
Intercambiar dos variables sin importar el tipo de datos
mismo tipo entre si
decimos el tipo
Programador: cams93
*/

#include <stdio.h>
#include "swap.h"

int testint(void);
int testintG(void);

int main(){
	testint();
	testintG();
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