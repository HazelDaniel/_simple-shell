#include "main.h"

void append_trash(trashenv_t *list, char *value, int index)
{
	trashenv_t* new_trash = (trashenv_t *)malloc(sizeof(trashenv_t)), *current;

	if (!new_trash)
		return;
	new_trash->value = _strddup(value);
	new_trash->index = (int*)malloc(sizeof(int));
	*(new_trash->index) = index;
	new_trash->next = NULL;

	if (!list)
	{
		list = new_trash;
	}
	else
	{
		current = list;

		while (current && current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_trash;
	}
}

void clear_trash(trashenv_t *list)
{
	trashenv_t *current = list, *next = NULL;

	if (!current)
		return;
	while (current)
	{
		if (current->next == NULL)
		{
			free(current->value);
			free(current->index);
			free(current);
			current = NULL;
			return;
		}
		next = current->next;
		free(current->value);
		free(current->index);
		free(current);
		current = next;
	}
	list = NULL;
}

void remove_trash(trashenv_t *list, char *value)
{
	trashenv_t *current = list, *prev = NULL;

	if (!current)
		return;
	while (current && (_strcmp(&(current->value), &value)))
	{
		prev = current;
		current = current->next;
	}
	if (current)
	{
		if (!prev)
			list = current->next;
		else
			prev->next = current->next;
		free(current->value);
		free(current->index);
		free(current);
		current = NULL;
	}
}

trashenv_t *get_trash(trashenv_t *list, char *value)
{
	trashenv_t *current = list, *prev = NULL;

	while (current && (_strcmp(&(current->value), &value)))
	{
		prev = current;
		current = current->next;
	}

	return (current);
}
