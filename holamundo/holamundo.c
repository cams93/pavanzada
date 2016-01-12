#include <stdio.h> //input output

int main(int argc, char *argv[])
{
	int i;
	for(i=1; i<argc; i++)
		printf("Hola Mundo %s \n", argv[i]);
	return 0;
}