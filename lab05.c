#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 1000

void main() {
	int sum = 0;
	int array1[MAX] __attribute__ ((aligned (16)));
	int array2[MAX] __attribute__ ((aligned (16)));
	int array3[MAX] __attribute__ ((aligned (16)));
	
	srand(time(NULL));

	for(int i = 0; i < 1000; i++){
		array1[i] = (rand() % 2001) - 1000;
		array2[i] = (rand() % 2001) - 1000;
	}


	for(int i = 0; i < 1000; i++){
		array3[i] = array1[i] + array2[i];
		sum += array3[i];
	}


	printf("Total array sum is: %d\n", sum);
}

