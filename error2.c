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

/**
 * pop_error - print error message when stack cannot be popped
 * @line_number: line in monty file where error occured.
 *
 * Return: EXIT_FAILURE
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * swap_error - print error message when stack cannot be swapped
 * @line_number: line in monty byte fle where error occured.
 *
 * Return: EXIT_FAILURE
 */
int swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	return (EXIT_FAILURE);
}
