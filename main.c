#include "utils/main.h"
/**
 * main - the entry point into the program
 * Return: int
 **/
int main(void)
{
	char *hello, *token, *hello0, *hello1, *hello2;
	char *hello_test = "hello \tworld\t  how  \t  is\tit";
	char *hello_test0 = "  \t  hello world how is it";
	char *hello_test1 = "ls\t -l";
	char *path_test = "/usr/bin/ls: /home/toughware/bin/mySubCypher:/usr/.local/shar/tmp/google-chrome2";

	hello = _trim(hello_test);
	hello0 = _trim(hello_test0);
	hello1 = _trim(hello_test1);
	hello2 = _trim(path_test);

	token = _strtok(hello, " \t");
	printf("token is :%s\n\n", token);
	while (token)
	{
		token = _strtok(NULL, " \t");
		printf("token is :%s\n\n", token);
	}
	// token = _strtok(hello0, " \t");
	// printf("token is :%s\n\n", token);
	// token = _strtok(NULL, " \t");
	// printf("token is :%s\n\n", token);
	// puts("-----");
	// token = _strtok(hello1, "- \t");
	// printf("token is :%s\n\n", token);
	// token = _strtok(NULL, "- \t");
	// printf("token is :%s\n\n", token);
	token = _strtok(hello2, ": ");
	printf("current dir=>%s\n", token);
	while (token)
	{
		token = _strtok(NULL, ": ");
		printf("current dir=>%s\n", token);
	}
	free(hello);
	free(hello0);
	free(hello1);
	free(hello2);

	return (0);

}
