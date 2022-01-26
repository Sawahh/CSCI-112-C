/* Sierra Stephens
 * 4/30/20
 * FINAL Pgm3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	double array[6], sum;
	FILE* fin = fopen("doubles.txt", "r"); // Find in file
	FILE* fout = fopen("out.bin", "wb"); // Make out file

	// Check for no file
	if (fin == NULL){
		printf("Could not open file");
		return(-1);
	}
	// Check that binary file was made
	if (fout == NULL){
		printf("Could not make out file");
		return(-1);
	}

	// Read in from file and store in array
	for (int i = 0; i < 5; i++){
		fscanf(fin, "%lf", &array[i]);
		sum += array[i]; // Add to sum
	}

	// Print to binary file
	fwrite(array, sizeof(double), 5, fout);

	// Print sum to screen
	printf("Sum of doubles: %.1lf\n", sum);
	return(0);
}
