#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 1000

void main() {
	int sum = 0;
	int array1[MAX],array2[MAX],array3[MAX];
	
	srand(1);

	for(int i = 0; i < 1000; i++){
		array1[i] = (rand() % 2000) - 1000;
		array2[i] = (rand() % 2000) - 1000;
		array3[i] = array1[i] + array2[i];
	}
	
	for(int i = 0; i < 1000; i++){
		sum += array3[i];
	}

	printf("Total array sum is: %d\n", sum);
}

