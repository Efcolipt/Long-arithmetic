#ifndef NUMBER_H
#define NUMBER_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct number
{
	unsigned int length;
	unsigned char sign;
	unsigned char* digits_array;
};

struct number create_empty_number()
{
	struct number number;
	number.length = 0;
	number.sign = 0;
	number.digits_array = NULL;

	return number;
}

void free_number(struct number* number)
{
	free(number->digits_array);

	number->length = 0;
	number->digits_array = NULL;
}

void add_digit_right(struct number* number, unsigned char digit)
{
	if (number->length == 0)
	{
		number->length = 1;
		number->digits_array = (unsigned char*)malloc(number->length);
	}
	else
	{
		number->length++;
		number->digits_array = (unsigned char*)realloc(number->digits_array, number->length);
	}

	if (number->digits_array == NULL)
	{
		printf("Can't reserve memory to add digit\n");
		exit(0);
	}

	number->digits_array[number->length - 1] = digit;
}

void add_digit_left(struct number* number, unsigned char digit)
{
	if (number->length == 0)
	{
		number->length = 1;
		number->digits_array = (unsigned char*)malloc(number->length);
	}
	else
	{
		number->length++;
		number->digits_array = (unsigned char*)realloc(number->digits_array, number->length);
	}

	if (number->digits_array == NULL)
	{
		printf("Can't reserve memory to add digit\n");
		exit(0);
	}

	for (unsigned int i = number->length - 1; i > 0; i--)
		number->digits_array[i] = number->digits_array[i - 1];
		
	number->digits_array[0] = digit;
}

#endif