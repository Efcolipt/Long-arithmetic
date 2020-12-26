#include <stdio.h>

#include "number.h"
#include "number_func.h"
#include "number_math.h"

void main()
{
	struct number number_1 = create_empty_number();
	struct number number_2 = create_empty_number();
	struct number add = create_empty_number();
	struct number sub = create_empty_number();
	struct number mul = create_empty_number();
	struct number pow = create_empty_number();
	struct number fact = create_empty_number();
	struct number sum = create_empty_number();

	printf("Enter first number : \n");
	number_1 = input_number();

	printf("\nEnter second number : \n");
	number_2 = input_number();

	printf("\n");

	print_number(number_1);
	printf("+\n");
	print_number(number_2);
	printf("=\n");
	add = addition(number_1, number_2);
	print_number(add);

	printf("\n");

	print_number(number_1);
	printf("-\n");
	print_number(number_2);
	printf("=\n");
	sub = subtraction(number_1, number_2);
	print_number(sub);
	
	printf("\n");

	print_number(number_1);
	printf("*\n");
	print_number(number_2);
	printf("=\n");
	mul = multiplication(number_1, number_2);
	print_number(mul);

	printf("\n");

	print_number(number_1);
	printf("^\n");
	print_number(number_2);
	printf("=\n");
	pow = power(number_1, number_2);
	if (number_2.sign == 1)
		printf("1/");
	print_number(pow);

	printf("\n");

	printf("!");
	print_number(number_1);
	printf("=\n");
	if(number_1.sign == 1)
		printf("not exist\n");
	else
	{
		fact = factorial(number_1);
		print_number(fact);
	}

	printf("\n");

	printf("sum from ");
	print_number(number_1);
	printf("to \n");
	print_number(number_2);
	printf("=\n");
	if (comp(number_1, number_2) == 1)
		printf("incorrect input\n");
	else
	{
		sum = sum_from_to(number_1, number_2);
		print_number(sum);
	}
	
	free_number(&number_1);
	free_number(&number_2);
	free_number(&add);
	free_number(&sub);
	free_number(&mul);
	free_number(&fact);
	free_number(&sum);
}