#include "monty.h"

/**
 * pchar_error - prints error message when stack_t list is empty
 * @line_number: The line in monty byte file where error occured
 * @err: The error details
 *
 * Return: EXIT_FAILURE
 */
int pchar_error(unsigned int line_number, char *err)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, err);
	return (EXIT_FAILURE);
}
