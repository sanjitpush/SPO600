#include <stdlib.h> 
#include <stdio.h>
#include <stdint.h>
#include "vol.h"

// Function to scale a sound sample using a volume_factor
// in the range of 0.00 to 1.00.
static inline int16_t scale_sample(int16_t sample, float volume_factor) {
	return (int16_t) (volume_factor * (float) sample);
}

int main() {
	float vol_factor = 0.75;
	//Lookup table
	int16_t*	lookup;
	lookup = (int16_t*) calloc(SAMPLES,sizeof(int16_t));
	
	int		x;
	int		ttl;

	// Seed the pseudo-random number generator
	srand(-1);

	// Fill the array with random data
	for (x = 0; x < SAMPLES; x++) {
		//multiple sample values by volume factor
		lookup[x] =(int16_t) (x % 65536)-32768 * vol_factor;
	}

	// ######################################
	// Sum up the data
	for (x = 0; x < SAMPLES; x++) {
		ttl = (ttl+lookup[x])%1000;
	}

	// Print the sum
	printf("Result: %d\n", ttl);

	return 0;

}

