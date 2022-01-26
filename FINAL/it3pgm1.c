/* Sierra Stephens
 * 4/30/20
 * FINAL Pgm 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[30];
	char area[5];
	char phone[10];
}Business_t;

// Function declaration
int read(Business_t business[]);
void print(Business_t business[], int j);

int main(void){
	Business_t businesses[10]; // Initialize struct array
	int num_bus = read(businesses); // Counter/read in file
	print(businesses, num_bus); // Printing
	printf("\n"); // Formatting
	return(0);
}

int read(Business_t business[]){
	int length = sizeof(char)*128; // Allows memory to change
	char *result;
	char name[20], area[5], phone[10]; // Temp storage
	int i = 0; // Counter
	
	result = (char*) malloc(length);
	if(result == NULL){ // Here we can break easy
		printf("Memory Failure");
		return (-1);
	}

	FILE *fin = fopen("phone_numbers.txt", "r"); // Open txt file
	if (fin == NULL){ // Check for error opening file
		printf("Failed to open file");
		return(-1);
	}

	// While loop to read in data and put in struct array
	while (fgets(result, length, fin) != NULL){
		strcpy(name, strtok(result, " "));
		strcpy(area, strtok(NULL, "-"));
		strcpy(phone, strtok(NULL, ","));

		// HERE IS WHERE I THINK MY FORMATTING IS BREAKING
		// IT IS PERFECT WHEN I DO NOT ATTEMPT TO ADD SPACES IN THE NAME
		// Add first char to name, this way we don't add a space
		strncat(business[i].name, &name[0],1);
                // Check for capital letters to split the name
                for (int x=1; x<strlen(name); x++){
                        char character = name[x]; // Define the char
                        int ascii = (int) character; // Get ascii value for compare
                        if (ascii >= 97 && ascii <= 122){ // If lowercase
                                strncat(business[i].name, &character, 1); // Add to name
                        }
                        else{ // Otherwise insert space after
                                strcat(business[i].name, " ");
                                strncat(business[i].name, &character, 1); // Then add char
                        }
                }
		strcpy(business[i].area, area); // Set area in struct array
		strcpy(business[i].phone, phone); // Set phone in struct array
		i++;
	}
	fclose(fin); // Close file
	return i; // Return count of businesses
}

void print(Business_t business[], int j){
	// For loop to print list out
	printf("\n");
	for (int i = 0; i < j; i++){
		printf("Business: %-18s Area code: %-6s Phone: %-10s",
				business[i].name, business[i].area,
				business[i].phone);
	}
	return;
}
