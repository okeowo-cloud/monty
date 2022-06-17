#include <stdlib.h>

char *get_int(int num);
unsigned int get_abs(int num);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buf(unsigned int temp, unsigned int base,
		char *buff, int buff_size);

/**
 * get_int - gets a character pointer to new string
 * containing int
 *
 * @num: number to conert to string
 * Return: is a pointer to newly converted string
 */
char *get_int(int num)
{
	unsigned int temp;

	int length = 0;

	long num_l = 0;

	char *ret;

	temp = get_abs(num);
	length = get_numbase_len(temp, 10);
	if (num < 0 || num_l < 0)
		length++; /* room for negative char */
	ret = malloc(length + 1); /* plus one for end of char */
	if (!ret)
		return (NULL);
	fill_numbase_buf(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * get_abs - function return absolute of a num
 * @num: is an integer
 * Return: is an unsigned integer
 */
unsigned int get_abs(int num)
{
	if (num < 0)
		return (-(unsigned int)num);
	return ((unsigned int)num);
}

/**
 * get_numbase_len - get length of number required for buffer
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: length of number without null termination
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain at least one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buf - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buf(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87; /* 10 becomes a, 11 = b, .. */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
