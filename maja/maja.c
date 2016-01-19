/*
Solucion http://acm.tju.edu.cn/toj/showp1218.html
Programador: cams93
*/

#include <stdio.h>

int get_majacolumn(int);

int main(){
	int willnumber;
	int majacolumn = 0, majarow = 0;

	//Read input
	scanf("%d",&willnumber);
	
	while(willnumber>0){

		//Process
		majacolumn = get_majacolumn(willnumber);

		//Print result
		printf("%d,%d\n",majacolumn,majarow);

		//Read input
		scanf("%d",&willnumber);
	}
	
	return 0;
}

int get_majacolumn(int willnumber){
	int column = 0;
	int currentcelda = 2;
	int mincolumn = 0, maxcolumn = 0;
	int maxcapacity = 1;
	int i;

	if(willnumber == 1)
		return 0;
	
	while(currentcelda < willnumber){
		mincolumn -= 1;
		maxcolumn += 1;
		maxcapacity += 1;
		//desplaza izquierda
		for(; column > mincolumn; column--, currentcelda++){
			if(currentcelda == willnumber)
				return column;
		}
		for(i = 0; i<maxcapacity; currentcelda++, i++){
			if(currentcelda == willnumber)
				return column;
		}
		for(column +=1; column < maxcolumn; column++, currentcelda++){
			if(currentcelda == willnumber)
				return column;
		}
		for(i = 0; i<maxcapacity-1; currentcelda++, i++){
			if(currentcelda == willnumber)
				return column;
		}
	}

	return column;
}

//get renglon viernes antes del mediodia