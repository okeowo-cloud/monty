#include "monty.h"

/**
 * set_last_opt_err - function set last element of op_tok to be an error
 * @error_code: is an Integer to store op_code as string
 * Return: Always void
 */
void set_last_opt_err(int error_code)
{
	int token_len, i = 0;

	char *exit_str, **new_token;

	token_len = len_tok_arr();
	new_token = malloc(sizeof(char *) * (token_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < token_len)
	{
		new_token[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_token);
		malloc_error();
		return;
	}
	new_token[i++] = exit_str;
	new_token[i] = NULL;
	free(op_toks);
	op_toks = new_token;
}
