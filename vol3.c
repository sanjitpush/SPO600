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

	// Allocate memory for large in and out arrays
	int16_t*	in;
	int16_t*	out;
	in = (int16_t*) calloc(SAMPLES, sizeof(int16_t));
	out = (int16_t*) calloc(SAMPLES, sizeof(int16_t));

	int		x;
	int		ttl;

	// Seed the pseudo-random number generator
	srand(-1);

	// Fill the array with random data
	for (x = 0; x < SAMPLES; x++) {
		in[x] = (rand()%65536)-32768;
	}
	

	//Convert 0.75 to a fix point integer by multiplying by
	//0b100000000 (which represents 1.00)
	int shift = 0b100000000 * 0.75;

 
	// ######################################
	// This is the interesting part!
	// Scale the volume of all of the samples
	for (x = 0; x < SAMPLES; x++) {
		//Shift result to the right by  8 since
		//I'm using 256 as the multiplier
		out[x] = in[x] * shift >> 8;
	}
	// ######################################

	// Sum up the data
	for (x = 0; x < SAMPLES; x++) {
		ttl = (ttl+out[x])%1000;
	}

	// Print the sum
	printf("Result: %d\n", ttl);

	return 0;

}

