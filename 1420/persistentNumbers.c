/*
Solucion http://acm.tju.edu.cn/toj/showp1420.html
Programador: cams93
*/

#include "persistentNumbers.h"

int array[100];
int setNumbers[5];

int cmpfunc (const void * b, const void * a)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]){
	int number;
	int result;
	number = atoi(argv[1]);
	if(number < 0){
		return 0;
	}
	result = findNumbers(number);
	if(result < 0){
		printf("There is no such number.\n");
		return 0;
	}
	printf("%d\n", result);
	return 0;
}

/* Find the smallest numbers of the mcm and store them in an array */
int findNumbers(int number){
	if(number < 10){
		return 10 + number;
	}
	int size = mcm(number);
	if(size < 0){
		return -1;
	}
	int minNum = array[size];
	int index = 0;
	for (size -= 1; size >= 0; size--){
		if(minNum * array[size] < 10){
			minNum = minNum * array[size];
		}
		else{
			setNumbers[index] = minNum;
			minNum = array[size];
			index++;
			if(size == 0){
				setNumbers[index] = minNum;
				index ++;
			}
		}
	}
	return calculateNumber(setNumbers, index);
}

int nextPr(int num)
{
    int c;
    if(num < 2)
        c = 2;
    else if (num == 2)
        c = 3;
    else if(num & 1){
        num += 2;
        c = isPrime(num) ? num : nextPr(num);
    } else
        c = nextPr(num-1);

    return c;
}

int isPrime(int num)
{
  	if((num & 1)==0)
        return num == 2;
    else {
        int i, limit = sqrt(num);
        for (i = 3; i <= limit; i+=2){
            if (num % i == 0)
                return 0;
        }
    }
    return 1;
}

/* Find mcm of a given number */
int mcm(int number){
	int factor = 2;
	int i = 0;
	while(number > 1){
		if (number % factor == 0){
			number = number / factor;
			array[i] = factor;
			i++;
		}
		else{
			factor = nextPr(factor);
			if(factor > 10){
				return -1;
			}
		}
		if(factor > number){
			return --i;
		}
	}
}

/* Sort the array of the smallest number and calculate final result */
int calculateNumber(int setNumbers[], int size){
	int smallestNum = 0;
	int multiplier = 1;
	int i;
	qsort(setNumbers, size, sizeof(int), cmpfunc);
	for(i = 0; i < size; i++){
		smallestNum += (multiplier * setNumbers[i]);
		multiplier *= 10; 
	}
	return smallestNum;
}