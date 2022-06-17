#include "monty.h"

/**
 * usage_error - Prints usage error message
 *
 * Return: EXIT_FAILURE always.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints Malloc error message
 *
 * Return: EXIT_FAILURE always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - Prints file opening error messages w/ file name.
 *
 * @filename: Name of file failed to open
 * Return: EXIT_FAILURE always.
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @op_code: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 * Return: EXIT_FAILURE always.
 */
int unknown_op_error(char *op_code, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_code);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: EXIT_FAILURE always.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
