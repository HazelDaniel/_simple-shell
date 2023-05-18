#include "utils/main.h"
char *_getalias(char *input);
char *_setalias(char *input);

char *alias(char *input)
{
	if (in_str('=', input))
		return (_setalias(input));
	return (_getalias(input));
}

char *_getalias(char *input)
{
	int i = 0;
	char *token, *cp_buffer = NULL;
	alias_t *current = aliases;

	while (current)
	{
		if (is_start_str(input, current->value))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

char *_setalias(char *input)
{
	alias_t* new_alias = (alias_t *)malloc(sizeof(alias_t)), *current;

	if (!new_alias)
		return (NULL);
	new_alias->value = _strddup(input);
	new_alias->next = NULL;

	if (!aliases)
	{
		aliases = new_alias;
	}
	else
	{
		current = aliases;

		while (current && current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_alias;
	}
	return (0);
}

void free_aliases(alias_t *list)
{
	alias_t *current = list, *next = NULL;

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

void print_aliases()
{
	alias_t *current = aliases, *next = NULL;

	if (!current)
		puts("(nil)");
	while (current)
	{
		printf("%s\n", current->value);
		current = current->next;
	}
}
