#include "swap.h"

void swap(int *pa, int *pb){
	int tmp;
	tmp = *pa; 
	*pa = *pb;
	*pb = tmp;
}

void swapgeneric(void * va, void * vb, int elemSize){
	char tmp[elemSize];
	memcpy(tmp,va, elemSize);
	memcpy(va, vb, elemSize);
	memcpy(vb, tmp, elemSize);
}

//memcpy(destino, origen, size)
//*pa quiero el contenido del apuntador pa
//sin asterisco es direccion
//& direccion de la variable es usada por el apuntador