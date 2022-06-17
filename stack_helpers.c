#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);


/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 * bottom (queue) of a stack_t.
 *
 * Return: always void.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initializes a stack_t stack with beginning
 * stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 * Return: If an error occurs - EXIT_FAILURE.
 * Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (malloc_error());
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = STACK;

	*stack = new_node;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 * of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 * If the stack_t is in queue mode - QUEUE (1).
 * Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);

	else if (stack->n == QUEUE)
		return (QUEUE);

	return (2);
}
