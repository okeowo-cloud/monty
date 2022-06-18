#include "monty.h"

/**
 * monty_mul - function multiplies the second top element
 * of the stack with the top element of the stack.
 * @stack: A pointer to the top mode element of a stack_t list
 * @line_number: The current working line of a monty byte file.
 *
 * Return: Always void
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_last_opt_err(short_stack_error(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}
