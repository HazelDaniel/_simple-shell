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
	linkpath(_getenv("PATH"));
	// print_path();
	char *res, *user = _getenv("USER");
	char *buff = NULL;
	int read = 0, status;
	size_t size;
	char **cmd, *prompts[10] = {"_$ ", " ___(host@username)\n|___: "};

	alias("hazel='daniel'");
	_setvar("xx=2");
	_setvar("v=3");
	buff = _getvar("$xx");
	printf("%s\n", buff);
	buff = _getvar("$v");
	printf("%s\n", buff);

	_freenv();
	free_aliases(aliases);
	free_vars(variables);

	return (0);
}
