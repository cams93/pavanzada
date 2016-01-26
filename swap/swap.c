#include "swap.h"

void swap(int *pa, int *pb){
	int tmp;
	tmp = *pa; 
	*pa = *pb;
	*pb = tmp;
}

//*pa quiero el contenido del apuntador pa
//sin asterisco es direccion
//& direccion de la variable es usada por el apuntador