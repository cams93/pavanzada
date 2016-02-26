#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lsearch.h"

int lsearch (int elem, int array[], int size){
	int i;
	for(i = 0; i < size; i++){
		if(elem == array[i]){
			return i;
		}
	}
	return -1;
}

void * lsearchgeneric(void *elem,  void *array, int elemSize, int size, int (*cmpf)(void *, void *)){
	int i = 0;
	void * address;
	for(i = 0; i<size; i++){
		address = (char *)array + i * elemSize;
		if(cmpf(elem, address)){
			return address;
		}
	}
	return 0;
}

