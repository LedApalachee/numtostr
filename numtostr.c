#include "numtostr.h"
#include <stdlib.h>
#include <math.h>

char* numtostr(int n)
{
	char digits_count = 1;
	char* string;

	for (int i = 10; n / i; i *= 10)
		++digits_count;

	string = (char*) malloc(sizeof(char) * digits_count +  sizeof(char) * (n < 0) + sizeof(char));

	if (n >= 0)
	{
		for (int i = digits_count-1; i >= 0; --i)
			string[digits_count - i - 1] = '0' + ((n / (int)pow(10, i)) % 10);
		string[digits_count] = '\0';
	}
	else
	{
		n *= -1;
		for (int i = digits_count-1; i >= 0; --i)
			string[digits_count - i] = '0' + ((n / (int)pow(10, i)) % 10);
		string[0] = '-';
		string[digits_count + 1] = '\0';
	}

	return string;
}