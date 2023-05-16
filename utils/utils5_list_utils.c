#include "main.h"

void append_comm(comm_list_t* list, char separator,
	const char* command, int status)
{
	comm_t* new_comm = (comm_t *)malloc(sizeof(comm_t)), *current;

	if (!new_comm)
		return;
	new_comm->separator = separator;
	new_comm->command = strdup(command);
	new_comm->status = (int*)malloc(sizeof(int));
	*(new_comm->status) = status;
	new_comm->next = NULL;

	if (!*list)
	{
		*list = new_comm;
	}
	else
	{
		current = *list;

		while (current && current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_comm;
	}
}

void append_comm_list(comm_list_t list, int *index)
{
	comm_list_t * tmp = commands;
	int p_len;

	if (!commands)
		commands = (comm_list_t *)malloc(sizeof(comm_list_t *));
	if (!commands)
		return;
	commands[*index] = list;
	p_len = _al_len_(commands) * sizeof(comm_list_t);
	commands = _realloc(commands, p_len, p_len + 1);
	if (!commands)
		commands = tmp;
	else
		commands[*index + 1] = NULL, (*index)++;
}

void print_comms(const comm_list_t list)
{
	const comm_t* current = list;

	puts("----------------------->");
	while (current != NULL)
	{
		printf("Command: %s\t Separator: %c\n", current->command, current->separator);
		current = current->next;
	}
	puts("----------------------->");
}

void print_comms_full()
{
	int i = 0, j = 0;
	comm_list_t current = NULL;

	for (; commands[i]; i++)
	{
		current = commands[i];
		print_comms(current);
		puts("======================>");
	}
}
