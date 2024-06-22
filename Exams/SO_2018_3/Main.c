/*
Lab exam SoSe 2018.
Lecture: IE-B1-SOL1 (Software construction 1)
*/
#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Function prototypes (provided by examiner) */
char* invertString(char*);
int countChar(char*, char);

int main() {
	char* string = "Welcome to IE-SO1!";
	char letter = 'e';
	char* reversedString = invertString(string);
	printf("%s", reversedString);
	printf("\n%d", countChar(string, letter));
	return 0;
}

char* invertString(char* string) {
	int length = (int)strlen(string);
	char* newString = (char*)malloc((length + 1) * sizeof(char));
	for (int i = 0; i < length; i++)
	{
		newString[i] = string[strlen(string) - i - 1];
	}
	newString[length] = '\0';

	return newString;
}

int countChar(char* string, char letter) {
	int length = (int)strlen(string);
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (string[i] == letter)
		{
			count++;
		}
	}
	return count;
}