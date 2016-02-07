/*
Solucion http://acm.tju.edu.cn/toj/showp1425.html
Programador: cams93
*/

#include <stdio.h>
#include <stdlib.h>

int calculation(int, int, int, int);

int main(int argc, char *argv[]){
	int position, first, second, third;
	position = atoi(argv[1]);
	first = atoi(argv[2]);
	second = atoi(argv[3]);
	third = atoi(argv[4]);
	if(position == first || first == second || second == third){
		return 0;
	}
	printf("%d\n", calculation(position, first, second, third));
	return 0;
}

int calculation(int position, int first, int second, int third){
	int totalDegrees = 0;
	int currentPosition = position;
	
	/*first number clockwise */
	if(currentPosition < first)
		totalDegrees += 40 - abs(currentPosition - first); 
	else
		totalDegrees += currentPosition - first;
	currentPosition = first;

	/*second number counter-clockwise */
	if(currentPosition < second)
		totalDegrees += abs(currentPosition - second); 
	else
		totalDegrees += 40 - (currentPosition - second);
	currentPosition =  second;

	/*third number clockwise */
	if(currentPosition < third)
		totalDegrees += 40 - abs(currentPosition - third); 
	else
		totalDegrees += currentPosition - third;

	/*total degrees calculation */
	totalDegrees = totalDegrees * 9 + 720 + 360;
	return totalDegrees;
}