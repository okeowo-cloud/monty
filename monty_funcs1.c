#include "monty.h"

int validate_op_toks(void);

/**
 * validate_op_toks - check if op_tok is valid
 *
 * Return: 0 if valid, 1 otherwise.
 */
int validate_op_toks(void)
{
	int i;

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
			return (1);
	}
	return (0);
}

/**
 * monty_push - Pushes a value to a stack_t linkedlist
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: Always void.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int val;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		set_last_opt_err(malloc_error());
		return;
	}
	if (op_toks[1] == NULL)
	{
		set_last_opt_err(no_int_error(line_number));
		return;
	}
	val = validate_op_toks();
	if (val == 1)
	{
		set_last_opt_err(no_int_error(line_number));
		return;
	}
	new->n = atoi(op_toks[1]);
	if (check_mode(*stack) == STACK) /* STACK mode insert at the top */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: Always void.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: Always void
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_last_opt_err(pint_error(line_number));
	}
	printf("%d\n", (*stack)->next->n);
}
