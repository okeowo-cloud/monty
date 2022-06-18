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
	stack_t *tmp = NULL;

	if ((*stack)->next->next == NULL || (*stack)->next == NULL)
	{
		set_last_opt_err(swap_error(line_number));
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
