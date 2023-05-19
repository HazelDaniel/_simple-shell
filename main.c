#include "utils/main.h"

/* GLOBAL DECLARATIONS */
comm_list_t *commands = NULL;
int comms_index;
char **new_environ = NULL;
trashenv_t *env_trash = NULL;
pathdir_t *path_list = NULL;
alias_t *aliases = NULL;

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
	// alias("toughware='hazel'");
	// alias("toughware='donut'");
	// alias("toughware='donut'");
	// alias("toughware='hazel'");
	// alias("magic='happens'");
	// alias("bad='boujee'");
	// alias("bad='better'");
	// alias("bad='ninja'");
	// alias("magic='works'");
	// alias("bad='boujee'");
	// alias("bad='awesome'");
	// alias("hazel='you'");
	// alias("evan='they'");
	buff = alias("nope");
	printf("%s",buff);

	_freenv();
	free_aliases(aliases);

	return (0);
}
