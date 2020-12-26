#ifndef NUMBER_FUNC_H
#define NUMBER_FUNC_H

#include <stdio.h>
#include <stdlib.h>

#include "number.h"

struct number input_number()
{
	struct number number = create_empty_number();

	while (1)
	{
		char c = getchar();

		if (c == '\n')
			break;
		else if ((c == '-') && (number.length == 0))
			number.sign = 1;
		else if ((c < '0') || (c > '9'))
		{
			printf("Wrong input");
			exit(0);
		}
		else
			add_digit_right(&number, c - '0');
	}

	return number;
}

void print_number(struct number number)
{
	if ((number.length == 0) || (number.digits_array == NULL))
		return;

	if (number.sign == 1)
		printf("-");

	for (unsigned int i = 0; i < number.length; i++)
		printf("%u", number.digits_array[i]);

	printf("\n");
}

void copy(struct number* a, struct number* b)
{
	for (unsigned int i = 0; i < b->length; i++)
		add_digit_right(a, b->digits_array[i]);

	a->sign = b->sign;
}

#endif
