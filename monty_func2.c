#include "monty.h"

/**
 * monty_swap - function swaps the top two elements of the stack.
 * @stack: A pointer to the top mode element of a stack_t linked list
 * @line_number: The current working line of a monty byte file
 *
 * Return: Always void
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_last_opt_err(short_stack_error(line_number, "swap"));
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

/**
 * monty_add - adds the top two elements of the stack.
 * @stack: A pointer to the top mode element of a stack_t linked list
 * @line_number: The current working line of a monty byte file
 *
 * Return: Always void
 */
void monty_add(stack_t **stack, unsigned int line_number)
{

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_last_opt_err(short_stack_error(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_nop - function does nothing
 * @stack: A pointer to the topmode element of a stack_t linked list
 * @line_number: The current workong line of a monty byte file
 *
 * Return: Always void
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
