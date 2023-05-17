#include "utils/main.h"

/* GLOBAL DECLARATIONS */
comm_list_t *commands = NULL;
int comms_index;
char **new_environ = NULL;
trashenv_t *env_trash = NULL;

/**
 * main - the entry point into the program
 * Return: int
 **/
int main(void)
{
	char *token, hello_cpy[1024], *log_token;
	char *command_list = "\tpwd;ls || echo hello world ; alx-milestones &&\
		echo hello world ; ps && ls || head -n 1 || whoami";
	char *path_test = "/usr/bin/ls:\
		/home/toughware/bin/mySubCypher:/usr/.local/share/tmp/google-chrome2";
	char *command = "ls";
	int cmp, i = 0, j = 0;

	_copyenv();

	i = parse_to_commands(command_list);
	if (i == -1)
		return (i);
	print_comms_full();
	free_commands();
	// printf("PATH is :%s\n", _getenv("PATH"));
	char *str1 = "SHELL";
	char *str2 = "SHELL", *str_cpy;
	i = _strcmp(&str1, &str2);
	// printf("i is %d\n", i);
	// // _setenv("what", "the_f");
	// // _unsetenv("what");
	// printf("what is :%s\n", _getenv("what"));
	// // _setenv("what", "not_the_f");
	// printf("what is :%s\n", _getenv("what"));
	// printf("user is :%s\n", _getenv("USER"));
	// // _setenv("hello", "world");
	// printf("hello is :%s\n", _getenv("world"));
	_setenv("hello", "world");
	_setenv("hello", "another_world");
	printf("hello is:%s\n", _getenv("hello"));
	// printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	_setenv("key", "value");
	printf("key is:%s\n", _getenv("key"));
	// printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	_setenv("foo", "bar");
	printf("foo is:%s\n", _getenv("foo"));
	// printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	_setenv("which", "what");
	printf("which is:%s\n", _getenv("which"));
	// printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	_setenv("daniel", "emmanuel");
	printf("daniel is:%s\n", _getenv("daniel"));
	// printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	puts("=====================");
	_unsetenv("daniel");
	// printf("daniel is:%s\n", _getenv("daniel"));
	printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	_setenv("thor", "ragnarok");
	printf("thor is:%s\n", _getenv("thor"));
	printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	_unsetenv("thor");
	_setenv("thor", "ragnarok");
	printf("the number of variables in the environment is :%d\n", _len_p((void *)new_environ));
	print_trash(env_trash);
	// _getAll_env();

	_freenv();

	return (0);
}

