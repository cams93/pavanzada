/*
Solucion http://acm.tju.edu.cn/toj/showp1218.html
Programador: cams93
*/

#include <stdio.h>

int get_majacolumn(int, int [][4]);
int get_majarow(int, int [][4]);

int main(){
	int willnumber = 0;
	int majacolumn = 0, majarow =0;
	
	int resultados[100][4];
	int j;
	for(j=0; j<100; j++){
		resultados[j][0]=resultados[j][1]=resultados[j][2]=resultados[j][3]=0;
		get_majacolumn(j+1, resultados);
		get_majarow(j+1, resultados);
	}
	
	while(1){
		//Read input
		scanf("%d",&willnumber);
		//Print result
		if(willnumber<=100 && resultados[willnumber-1][2]==1 && resultados[willnumber-1][3]==1){
			printf("%d,%d\n",resultados[willnumber-1][0],resultados[willnumber-1][1]);
		}
		else{
			printf("The value that you entered has not been calculated yet\n");
		}
	}
	return 0;
}

int get_majacolumn(int willnumber, int resultados[][4]){
	int column = 0;
	int currentcelda = 1;
	int mincolumn = 0, maxcolumn = 0;
	int maxcapacity = 1;
	int i;
	resultados[willnumber-1][0]=0;
	if (willnumber == 1){
		resultados[willnumber-1][2]=1;
		return  0;
	}
	while(currentcelda < willnumber){
		currentcelda += 1;
		resultados[willnumber-1][0]=column;
		if (currentcelda == willnumber){
			resultados[willnumber-1][2]=1;
			return column;
		}
		mincolumn -= 1;
		maxcolumn += 1;
		maxcapacity += 1;
		column -= 1;
		//desplaza izquierda
		for(currentcelda += 1;column > mincolumn ; column--,currentcelda++){
			resultados[willnumber-1][0]=column;
			if(currentcelda == willnumber){
				resultados[willnumber-1][2]=1;
				return column;
			}
		}
		for(i = 0;i<maxcapacity;currentcelda++,i++){
			resultados[willnumber-1][0]=column;
			if(currentcelda == willnumber){
				resultados[willnumber-1][2]=1;
				return column;
			}
		}
		for(column += 1;column < maxcolumn ; column++,currentcelda++){
			resultados[willnumber-1][0]=column;
			if(currentcelda == willnumber){
				resultados[willnumber-1][2]=1;
				return column;
			}
		}
		for(i = 0;i<maxcapacity -1;currentcelda++,i++){
			resultados[willnumber-1][0]=column;
			if(currentcelda == willnumber){
				resultados[willnumber-1][2]=1;
				return column;
			}
		}
	}
	resultados[willnumber-1][0]=column;
	resultados[willnumber-1][2]=1;
	return column;
}
int get_majarow(int willnumber, int resultados[][4]){
	int row = 0;
	int currentcelda = 1;
	int minrow = 0, maxrow = 0;
	int maxcapacity = 1;
	int i;
	int pass=0;
	resultados[willnumber-1][1]=0;
	if (willnumber == 1){
		resultados[willnumber-1][3]=1;
		return  0;
	}
	resultados[willnumber-1][1]=1;
	if (willnumber == 2 || willnumber == 3){
		resultados[willnumber-1][3]=1;
		return 1;
	}
		
	while(currentcelda < willnumber){
		currentcelda += 1;
		row += 1;
		resultados[willnumber-1][1]=row;
		if (currentcelda == willnumber) {
			resultados[willnumber-1][3]=1;
			return row;
		}
		minrow -= 1;
		maxrow += 1;
		maxcapacity += 1;
	
		//desplaza derecha
		for(currentcelda += 1; row < maxrow; currentcelda++){
			row++;
			resultados[willnumber-1][1]=row;
			if(currentcelda == willnumber){
				resultados[willnumber-1][3]=1;
				return row;
			}
		}
		for(i = 0; i<maxcapacity -1; currentcelda++, i++){
			resultados[willnumber-1][1]=row;
			if(currentcelda == willnumber){
				resultados[willnumber-1][3]=1;
				return row;
			}
		}
		for(row -= 1; row > minrow; row--, currentcelda++){
			resultados[willnumber-1][1]=row;
			if(currentcelda == willnumber){
				resultados[willnumber-1][3]=1;
				return row;
			}
		}
		for(i = 0; i<maxcapacity; currentcelda++, i++){
			resultados[willnumber-1][1]=row;
			if(currentcelda == willnumber){
				resultados[willnumber-1][3]=1;
				return row;
			}
		}
		row++;
	}
	resultados[willnumber-1][1]=row;
	resultados[willnumber-1][3]=1;
	return row;
}

//get renglon viernes antes del mediodia