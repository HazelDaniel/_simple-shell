#include "utils/main.h"

/* GLOBAL DECLARATIONS */
comm_list_t *commands = NULL;
int comms_index;
char **new_environ = NULL;
trashenv_t *env_trash = NULL;
pathdir_t *path_list = NULL;

/**
 * main - the entry point into the program
 * Return: int
 **/
int main(void)
{
	_copyenv();
	linkpath(_getenv("PATH"));
	// print_path();
	char *res;
	char *buff = NULL;
	int read, status;
	size_t size;
	char **cmd;

	// res = _strdcat(buff, "hello world");
	// res = _strdcat(res, ", how is it going");
	// printf("result is :%s\n", res);
	// free(res);
	// res = _trace("ls");
	// printf("ls: command can be found in :%s\n", res);
	while (1)
	{
		buff = malloc(1);
		if (read == EOF)
			break;
		read = _getline(&buff, &size, STDIN_FILENO);
		if (read != -1)
		{
			status = parse_to_commands(buff);
			if (status == -1)
				return (status);
			print_comms_full();
		}
		free(buff);
		buff = NULL;
	}


	_freenv();

	return (0);
}
