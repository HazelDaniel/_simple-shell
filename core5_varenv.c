#include "utils/main.h"

static int compare_and_sub(var_t **current_ptr, var_t **new_ptr,
	char **input_ptr, char **cpy_ptr, char **key_ptr);

void _getall_vars()
{
	int i = 0;
	var_t *current = variables;

	if (!current)
		puts("(nil)");

	while(current)
	{
		printf("%s\n", current->value);
		current = current->next;
	}
}

char *_getvar(char *input)
{
	int i = 0;
	char *token, *cp_buffer = NULL, *tok_cpy = NULL;
	var_t *current = variables;

	if (!current || !input || !is_start_str("$", input))
		return (NULL);
	while (current)
	{
		if (is_start_str(input + 1, current->value))
		{
			cp_buffer = _strddup(current->value);
			(void)_strtok(cp_buffer, "=");
			token = _strtok(NULL, "=");
			tok_cpy = _strddup(token);
			empty_state_buff("=");
			free(cp_buffer), cp_buffer = NULL;
			return (tok_cpy);
		}
		current = current->next;
	}

	return (NULL);
}

char *_setvar(char *input)
{
	var_t *current = variables, *new_var, *prev;
	char *cpy = _strddup(input), *key = _strtok(cpy, "=");

	if (is_start_str("$", input))
		return (NULL);

	new_var = (var_t *)malloc(sizeof(var_t));
	if (!new_var)
		return (NULL);
	new_var->value = _strddup(input);
	new_var->next = NULL;
	empty_state_buff("=");
	if (!variables)
	{
		variables = new_var;
		return (new_var->value);
	}
	current = variables;

	if (!current->next)
	{
		if (compare_and_sub(&current,
		&new_var, &input, &cpy, &key))
			return (current->value);
		current->next = new_var;
		return (new_var->value);
	}
	while (current && current->next)
	{
		if (compare_and_sub(&current,
		&new_var, &input, &cpy, &key))
			return (current->value);
		current = current->next;
	}
	if (compare_and_sub(&current,
	&new_var, &input, &cpy, &key))
		return (current->value);
	current->next = new_var;
	free(cpy);

	return (new_var->value);
}

static int compare_and_sub(var_t **current_ptr, var_t **new_ptr,
	char **input_ptr, char **cpy_ptr, char **key_ptr)
{
	if (!_strcmp(((*current_ptr)->value), *input_ptr))
	{
		free((*new_ptr)), free(*cpy_ptr);
		return (1);
	}
	else if (is_start_str(*key_ptr, (*current_ptr)->value))
	{
		free((*current_ptr)->value);
		(*current_ptr)->value = _strddup(*input_ptr);
		return (1);
	}

	return (0);
}

void free_vars(var_t *list)
{
	var_t *current = list, *next = NULL;

	if (!current)
		return;
	while (current)
	{
		if (current->next == NULL)
		{
			free(current->value);
			free(current);
			current = NULL;
			return;
		}
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	list = NULL;
}
