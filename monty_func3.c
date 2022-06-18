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

/**
 * monty_mod - function computes the rest of the division
 * of the second top element of the stack by the top element of the stack.
 * @stack: A pointer to the top mode element of a stack_t list
 * @line_number: The current working line of a monty byte file.
 *
 * Return: Always void
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_last_opt_err(short_stack_error(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_last_opt_err(zero_div_error(line_number));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_pchar - function prints the char at the top
 * of the stack, followed by a new line.
 *
 * @stack: A pointer to the top mode of mode element of a stack_t list
 * @line_number: The current working line of a monty byte file.
 *
 * Return: Always void
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_last_opt_err(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_last_opt_err(pchar_error(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}


/**
 * monty_pstr - function prints the string starting at the
 * top of the stack, followed by a new line.
 * @stack: A pointer to the top mode of element of a stack_t list
 * @line_number: The current working line of a monty byte file.
 *
 * Return: Always void
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *next = (*stack)->next;

	while (next && next->n != 0 && (next->n > 0 && next->n <= 127))
	{
		printf("%c", next->n);
		next = next->next;
	}
	(void)line_number;
	printf("\n");
}
