#include "utils/main.h"
/**
 * main - the entry point into the program
 * Return: int
 **/
int main(void)
{
	char *hello, *token, *hello0, *hello1, *hello2, hello_cpy[1024] = "";
	char *hello_test = "hello \tworld\t  how  \t  is\tit";
	char *hello_test0 = "";
	char *hello_test1 = "ls\t -l";
	char *path_test = "/usr/bin/ls: /home/toughware/bin/mySubCypher:/usr/.local/shar/tmp/google-chrome2";

	hello = _trim(hello_test);
	hello0 = _trim(hello_test0);
	hello1 = _trim(hello_test1);
	hello2 = _trim(path_test);

	token = _strtok(_strcpy(&hello_cpy, &hello), " \t");
	printf("token is :%s\n\n", token);
	while (token)
	{
		token = _strtok(NULL, " \t");
		printf("token is :%s\n\n", token);
	}
	token = _strtok(_strcpy(&hello_cpy, &hello1), " -");
	printf("token is :%s\n\n", token);
	while (token)
	{
		token = _strtok(NULL, " -");
		printf("token is :%s\n\n", token);
	}
	token = _strtok(_strcpy(&hello_cpy, &hello0), " \t");
	printf("token is :%s\n\n", token);
	while (token)
	{
		token = _strtok(NULL, " \t");
		printf("token is :%s\n\n", token);
	}
	token = _strtok(_strcpy(&hello_cpy, &hello2), ": ");
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
