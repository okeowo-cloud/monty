#include "monty.h"
#include <string.h>

void free_token(void);
unsigned int len_tok_arr(void);
int is_line_empty(char *line, char *delims);
void (*get_op_func(char *op_code))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_token - Frees the global op_toks array of strings.
 *
 * Return: Always void.
 */
void free_token(void)
{
	size_t i;

	if (op_toks == NULL)
		return;
	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * len_tok_arr - return the length of global op_toks
 *
 * Return: is an unsigned int
 */
unsigned int len_tok_arr(void)
{
	unsigned int len = 0;

	while (op_toks[len])
		len++;

	return (len);
}

/**
 * is_line_empty - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: 1 if line contains delimeter, 0 otherwise.
 */
int is_line_empty(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}


/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @op_code: The opcode to match.
 *
 * Return: a pointer to the corresponding function.
 */
void (*get_op_func(char *op_code))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{NULL, NULL}
	};

	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(op_code, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * run_monty - main function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char line[BUFSIZE];
	size_t exit_status = EXIT_SUCCESS;

	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (fgets(line, BUFSIZE, script_fd) != NULL)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_line_empty(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_token();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_token();
			break;
		}
		prev_tok_len = len_tok_arr();
		op_func(&stack, line_number);
		if (len_tok_arr() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_token();
			break;
		}
		free_token();
	}
	free_stack(&stack);
	return (exit_status);
}
