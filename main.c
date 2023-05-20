#include "utils/main.h"

/* GLOBAL DECLARATIONS */
comm_list_t *commands = NULL;
int comms_index;
char **new_environ = NULL;
trashenv_t *env_trash = NULL;
pathdir_t *path_list = NULL;
alias_t *aliases = NULL;
var_t *variables = NULL;

/**
 * main - the entry point into the program
 * Return: int
 **/
int main(void)
{
	_copyenv();
	char *buff = NULL, **vectors = NULL,
	*line;
	int i;

	vectors = _splitstr("hello ;world ;this ;is ;me.", ";");
	buff = join_list(vectors);
	free_str_arr(vectors, 1);
	// printf("buffer is now :%s\n", buff);
	free(buff);
	// for (i = 0; vectors[i]; i++)
	// {
	// 	printf("-%s\n", vectors[i]);
	// }
	vectors = word_tok("hello world here we are?");
	if (vectors)
	{
		buff = join_list(vectors);
		printf("words are :%s\n", buff);
		free_str_arr(vectors, 1);
	}

	buff = _setvar("xx=2");
	buff = _setvar("$=0");
	buff = _setvar("v=3");
	buff = _setvar("?=1");
	buff = _getvar("$?");
	printf("buff=>%s\n", buff);
	free(buff);
	// buff = _getvar("$v");
	puts("we're here");
	buff = lookup_var("$USER");
	printf("user is %s\n", buff);
	free(buff);
	buff = NULL;
	// line = "$TERM hello $$ $ $? $h $xx people $v! ";
	line = "$TERM hello $$ $ $? $h $xx people $v! ";
	buff = expand(line);
	printf("expanded version is :%s\n", buff);
	_getall_vars();


	_freenv();
	free_aliases(aliases);
	free_vars(variables);

	return (0);
}
