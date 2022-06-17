#include "monty.h"

/**
 * pint_error - print error mesaage when stack is empty
 * @line_number: error line number.
 *
 * Return: EXIT_FAILURE
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
