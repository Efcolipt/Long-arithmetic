#ifndef NUMBER_MATH_H
#define NUMBER_MATH_H

#include "number.h"

struct number addition(struct number a, struct number b);

struct number subtraction(struct number a, struct number b);

struct number multiplication(struct number a, struct number b);

struct number power(struct number a, struct number n);

struct number factorial(struct number a);

struct number sum_from_to(struct number a, struct number b);


struct number add(struct number a, struct number b);

struct number sub(struct number a, struct number b);

struct number mult(struct number a, struct number b);

struct number pow(struct number a, struct number n);

struct number sum(struct number a, struct number b);


char comp(struct number a, struct number b)
{
	if ((a.sign == 0) && (b.sign == 1))
		return 1;
	else if ((b.sign == 0) && (a.sign == 1))
		return -1;
	else
		if (a.length > b.length)
			return 1;
		else if (a.length < b.length)
			return -1;
		else
		{
			for (unsigned short i = 0; i < a.length; i++)
			{
				if (a.digits_array[i] > b.digits_array[i])
					return 1;
				else if (a.digits_array[i] < b.digits_array[i])
					return -1;
			}
		}

	return 0;
}

unsigned char zero_check(struct number a)
{
	if ((a.length == 1) && (a.digits_array[0] == 0))
		return 1;

	return 0;
}

struct number inc(struct number a)
{
	struct number one = create_empty_number();
	add_digit_right(&one, 1);

	a = addition(a, one);

	return a;
}

struct number dec(struct number a)
{
	struct number one = create_empty_number();
	add_digit_right(&one, 1);

	a = subtraction(a, one);

	return a;
}

unsigned char is_even(struct number a)
{
	if (a.digits_array[a.length - 1] % 2 == 0)
		return 1;

	return 0;
}


struct number addition(struct number a, struct number b)
{
	if ((a.sign == 0) && (b.sign == 0))
		return add(a, b);
	else if ((a.sign == 1) && (b.sign == 0))
	{
		a.sign = 0;
		return subtraction(b, a);
	}	
	else if ((a.sign == 0) && (b.sign == 1))
		return subtraction(a, b);
	else
	{
		struct number tmp = add(a, b);
		tmp.sign = 1;
		return tmp;
	}
}

struct number subtraction(struct number a, struct number b)
{
	struct number sub_number = create_empty_number();
	char comparison = comp(a, b);

	if ((a.sign == 0) && (b.sign == 0))
		if (comparison == 0)
		{
			add_digit_right(&sub_number, 0);
			return sub_number;
		}
		else if (comparison == 1)
			return sub(a, b);
		else
		{
			sub_number = sub(b, a);
			sub_number.sign = 1;
			return sub_number;
		}
	else if ((a.sign == 1) && (b.sign == 0))
	{
		struct number tmp = add(a, b);
		tmp.sign = 1;
		return tmp;
	}
	else if ((a.sign == 0) && (b.sign == 1))
		return add(a, b);
	else
	{
		a.sign = 0;
		b.sign = 0;
		return subtraction(b, a);
	}
}

struct number multiplication(struct number a, struct number b)
{
	if (zero_check(a) || zero_check(b))
	{
		struct number tmp = create_empty_number();
		add_digit_left(&tmp, 0);
		return tmp;
	}

	if (zero_check(dec(a)))
	{
		struct number tmp = create_empty_number();
		copy(&tmp, &b);
		return tmp;
	}
		
	if (zero_check(dec(b)))
	{
		struct number tmp = create_empty_number();
		copy(&tmp, &a);
		return tmp;
	}

	if ((a.sign == 0) && (b.sign == 0))
	{
		if(comp(a, b) == -1)
			return mult(b, a);
		else 
			return mult(a, b);
	}
	else if ((a.sign == 1) && (b.sign == 0))
	{
		struct number tmp;

		if (comp(a, b) == -1)
			tmp = mult(b, a);
		else
			tmp = mult(a, b);

		tmp.sign = 1;
		return tmp;
	}
	else if ((a.sign == 0) && (b.sign == 1))
	{
		struct number tmp;

		if (comp(a, b) == -1)
			tmp = mult(b, a);
		else
			tmp = mult(a, b);

		tmp.sign = 1;
		return tmp;
	}
	else
	{
		if (comp(a, b) == -1)
			return mult(b, a);
		else
			return mult(a, b);
	}
}

struct number power(struct number a, struct number n)
{
	if (zero_check(a))
	{
		struct number tmp = create_empty_number();
		add_digit_left(&tmp, 0);
		return tmp;
	}

	if (zero_check(dec(a)))
	{
		struct number tmp = create_empty_number();
		add_digit_left(&tmp, 1);
		return tmp;
	}

	if (zero_check(n))
	{
		struct number tmp = create_empty_number();
		add_digit_left(&tmp, 1);
		return tmp;
	}

	if (zero_check(dec(n)))
	{
		struct number tmp = create_empty_number();
		copy(&tmp, &a);
		return tmp;
	}

	if (a.sign)
		if (!is_even(n))
		{
			struct number tmp = pow(a, n);
			tmp.sign = 1;
			return tmp;
		}
		else
			return pow(a, n);

	return pow(a, n);
}

struct number factorial(struct number a)
{
	a.sign = 0;

	if (zero_check(a))
	{
		struct number tmp = create_empty_number();
		add_digit_left(&tmp, 1);
		return tmp;
	}

	return multiplication(a, factorial(dec(a)));
}

struct number sum_from_to(struct number a, struct number b)
{
	return sum(a, b);
}


struct number add(struct number a, struct number b)
{
	struct number sum_number = create_empty_number();

	unsigned char carry = 0;
	short num_1_i = a.length - 1;
	short num_2_i = b.length - 1;

	while ((num_1_i >= 0) || (num_2_i >= 0))
	{
		char number_1_digit = (num_1_i >= 0) ? a.digits_array[num_1_i--] : 0;
		char number_2_digit = (num_2_i >= 0) ? b.digits_array[num_2_i--] : 0;

		unsigned char digit = number_1_digit + number_2_digit + carry;

		add_digit_left(&sum_number, digit % 10);

		carry = digit / 10;
	}

	if (carry)
		add_digit_left(&sum_number, carry);

	return sum_number;
}

struct number sub(struct number a, struct number b)
{
	struct number sub_number = create_empty_number();

	unsigned char carry = 0;
	short num_1_i = a.length - 1;
	short num_2_i = b.length - 1;

	while ((num_1_i >= 0) || (num_2_i >= 0))
	{
		char number_1_digit = (num_1_i >= 0) ? a.digits_array[num_1_i--] : 0;
		char number_2_digit = (num_2_i >= 0) ? b.digits_array[num_2_i--] : 0;

		number_1_digit -= carry;

		if (number_1_digit < number_2_digit)
		{
			carry = 1;
			number_1_digit += 10;
		}
		else
			carry = 0;

		char digit = number_1_digit - number_2_digit;

		if ((digit == 0) && (num_1_i < 0) && (num_2_i < 0))
			continue;

		add_digit_left(&sub_number, digit);
	}

	return sub_number;
}

struct number mult(struct number a, struct number b)
{
	a.sign = 0;
	b.sign = 0;

	struct number mult = create_empty_number();
	copy(&mult, &a);

	b = dec(b);
	for (; !zero_check(b); b = dec(b), mult = addition(a, mult));

	return mult;
}

struct number pow(struct number a, struct number n)
{
	a.sign = 0;
	n.sign = 0;

	struct number pow = create_empty_number();
	copy(&pow, &a);

	n = dec(n);
	for (; !zero_check(n); n = dec(n), pow = multiplication(a, pow));

	return pow;
}

struct number sum(struct number a, struct number b)
{
	if (comp(a, b) == 0)
	{
		struct number tmp = create_empty_number();
		copy(&tmp, &a);
		return tmp;
	}

	return addition(a, sum(inc(a), b));
}

#endif
