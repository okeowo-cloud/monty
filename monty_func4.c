#include "monty.h"

/**
 * monty_rotr - function rotates the stack to the bottom.
 * @stack: A pointer to the top mode of a stack_t list
 * @line_number: The current working line of a monty byte file.
 *
 * Return: Always void
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (botom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->next = top;
	bottom->prev = *stack;
	top->prev = bottom;

	(void)line_number;
}


/**
 * monty_queue - function sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top mode of a stack_t list
 * @line_number: The current working line of a monty byte file.
 *
 * Return: Always void.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

/**
 * monty_stack - function sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top mode of a stack_t list
 * @line_number: The current working line of a monty byte file.
 *
 * Return: Always void
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
