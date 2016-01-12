#include <stdio.h> //input output

int main(int argc, char *argv[])
{
	int i=1;
	while(i<argc)
	{
		printf("Hola Mundo %s \n", argv[i]);
		i++;
	}
	return 0;
}