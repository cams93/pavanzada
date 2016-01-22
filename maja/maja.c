/*
Solucion http://acm.tju.edu.cn/toj/showp1218.html
Programador: cams93
*/

#include <stdio.h>

int get_majacolumn(int);
int get_majarow(int);

int main(){
	int willnumber = 0;
	int majacolumn = 0, majarow =0;

	//Read input
	scanf("%d",&willnumber);
	while(willnumber >0){
		//Process
		majacolumn = get_majacolumn(willnumber);
		majarow =  get_majarow(willnumber);
		//Print result
		printf("%d,%d\n",majacolumn,majarow);
		//Read input
		scanf("%d",&willnumber);
	}
	return 0;
}

int get_majacolumn(int willnumber){
	int column = 0;
	int currentcelda = 1;
	int mincolumn = 0, maxcolumn = 0;
	int maxcapacity = 1;
	int i;
	if (willnumber == 1)
		return  0;
	while(currentcelda < willnumber){
		currentcelda += 1;
		if (currentcelda == willnumber) return column;
		mincolumn -= 1;
		maxcolumn += 1;
		maxcapacity += 1;
		column -= 1;
		//desplaza izquierda
		for(currentcelda += 1;column > mincolumn ; column--,currentcelda++){
			if(currentcelda == willnumber)
				return column;
		}
		for(i = 0;i<maxcapacity;currentcelda++,i++){
			if(currentcelda == willnumber)
				return column;
		}
		for(column += 1;column < maxcolumn ; column++,currentcelda++){
			if(currentcelda == willnumber)
				return column;
		}
		for(i = 0;i<maxcapacity -1;currentcelda++,i++){
			if(currentcelda == willnumber)
				return column;
		}


	}
	return column;
}
int get_majarow(int willnumber){
	int row = 0;
	int currentcelda = 1;
	int minrow = 0, maxrow = 0;
	int maxcapacity = 1;
	int i;
	int pass=0;
	if (willnumber == 1)
		return  0;
	if (willnumber == 2 || willnumber == 3)
		return 1;
		
	while(currentcelda < willnumber){
		currentcelda += 1;
		row += 1;
		if (currentcelda == willnumber) {
			return row;
		}
		minrow -= 1;
		maxrow += 1;
		maxcapacity += 1;
	
		//desplaza derecha
		for(currentcelda += 1; row < maxrow; currentcelda++){
			row++;
			if(currentcelda == willnumber)
				return row;
		}
		for(i = 0; i<maxcapacity -1; currentcelda++, i++){
			if(currentcelda == willnumber)
				return row;
		}
		for(row -= 1; row > minrow; row--, currentcelda++){
			if(currentcelda == willnumber)
				return row;
		}
		for(i = 0; i<maxcapacity; currentcelda++, i++){
			if(currentcelda == willnumber)
				return row;
		}
		row++;
	}
	return row;
}

//get renglon viernes antes del mediodia