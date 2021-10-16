#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

char** result;


char** decimalToDecimal(int argc, char* argv[])
{
	char* result = malloc(sizeof(char*) * 100);
	for (int i = 2; i < argc; i++) {
		int length = 0;
		char* pos = argv[i];
		while (*pos++ != '\0') {
			length++;
		}
		pos = argv[i];
		int decimal = 0;
		while (*pos != '\0') {
			if (isdigit(pos)) {
				decimal += ((int)*pos-'0')*pow(10,length--);
			} else {
				decimal += ((int)*pos-'a'+10)*pow(10,length--);
			}
			pos++;
		}
		printf("%d\n", decimal);
	}
	printf("hi");
	return result;
}

char** decimalToBinary(int argc, char* argv[])
{
	char* result = malloc(sizeof(char) * 100);

	sprintf(argv[2], result, 2);

	return result;
}

char** decimalToHex(int argc, char* argv[])
{
	char* result = malloc(sizeof(char) * 100);

	sprintf(argv[2], result, 16);

	return result;
}

char** binaryToDecimal(int argc, char* argv[])
{
	char** result = malloc(sizeof(char) * 100);

	sprintf(argv[2], result, 10);

	return result;
}

char** binaryToBinary(int argc, char* argv[])
{
	char** result = malloc(sizeof(char) * 100);

	return result;
}

char** binaryToHex(int argc, char* argv[])

{
	char** result = malloc(sizeof(char) * 100);

	sprintf(argv[2], result, 16);

	return result;
}

char** hexToDecimal(int argc, char* argv[])
{
	char** result = malloc(sizeof(char) * 100);

	sprintf(argv[2], result, 10);

	return result;
}
char** hexToBinary(int argc, char* argv[])
{
	char** result = malloc(sizeof(char) * 100);

	sprintf(argv[2], result, 2);

	return result;
}
char** hexToHex(int argc, char* argv[])
{
	char** result = malloc(sizeof(char) * 100 * (argc-2));


	return result;
}

// Redirect to corresponding function
void seekUserInput(int argc, char* argv[]) {
	if (strcmp(argv[0], "binary") && strcmp(argv[1], "decimal")) result = binaryToDecimal(argc, argv);
	else if (strcmp(argv[0], "binary") && strcmp(argv[1], "binary")) result = binaryToBinary(argc, argv);
	else if (strcmp(argv[0], "binary") && strcmp(argv[1], "hex")) result = binaryToHex(argc, argv);
	else if (strcmp(argv[0], "decimal") && strcmp(argv[1], "decimal")) result = decimalToDecimal(argc, argv);
	else if (strcmp(argv[0], "decimal") && strcmp(argv[1], "binary")) result = decimalToBinary(argc, argv);
	else if (strcmp(argv[0], "decimal") && strcmp(argv[1], "hex")) result = decimalToHex(argc, argv);
	else if (strcmp(argv[0], "hex") && strcmp(argv[1], "decimal")) result = hexToDecimal(argc, argv);
	else if (strcmp(argv[0], "hex") && strcmp(argv[1], "binary")) result = hexToBinary(argc, argv);
	else if (strcmp(argv[0], "hex") && strcmp(argv[1], "hex")) result = hexToHex(argc, argv);
}

// Check if user input contains letters
bool inputValidation(int argc, char* argv[]) {
	if (strcmp(argv[0], "binary") || strcmp(argv[0], "decimal") || strcmp(argv[0], "hex")) {
		for (int i = 2; i < argc; i += 1) {
			char* pos = argv[i];
			while (*pos != '\0') {
				if (!isdigit(*(pos)) && *(pos) != 'a' && *(pos) != 'b' && *(pos) != 'c' && *(pos) != 'c' && *(pos) != 'd' && *(pos) != 'e' && *(pos) != 'f') return false;
				pos++;
			}
		}
		return true;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("ERROR: You have to insert at least 3 argumetns.");
		return 0;
	}
	result = (char**)malloc(argc * 4);
	if (inputValidation(argc, argv))
		seekUserInput(argc, argv);


	printf("%x\n", result, "System exit.");
	return 0;

}
