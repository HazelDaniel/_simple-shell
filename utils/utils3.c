#include "main.h"

char **_splitstr(char *str, char *delim)
{
	char **res_str = NULL, *token, cp_buff[1024] = "", *res_buff[1024] = {NULL};
	size_t count = 0, res_index = 0, i = 0;

	if (!str)
		return (NULL);
	token = _strtok(__cp__(cp_buff, str), delim);
	while (token)
	{
		count = 0;
		while (token[count])
			count++;
		res_buff[res_index] = malloc((count + 1) * sizeof(char));
		if (!res_buff[res_index])
		{
			for (i = 0; i < res_index; i++)
				free(res_buff[i]);
			return (NULL);
		}
		res_buff[res_index][count] = '\0';
		for (i = 0; token[i]; i++)
			res_buff[res_index][i] = token[i];
		token = _strtok(NULL, delim);
		res_index++;
	}

	res_str = malloc((res_index + 1) * sizeof(char *));
	if (res_str == NULL)
	{
		free_str_arr(res_buff, 0);
		return (NULL);
	}
	res_str[res_index] = NULL;

	for (i = 0; i < res_index; i++)
		res_str[i] = res_buff[i];

	return (res_str);
}

/**
 * _strddup - a function that returns a duplicate, dynamically
 * allocated array of characters
 * @src: the source string
 * Return: the duplicated string
 **/
char *_strddup(char *src)
{
	int i = 0, len = _strlen(src);
	char *res = NULL;

	if (!src)
		return (NULL);
	res = malloc((len + 1));
	if (!res)
		return (res);
	res[len] = '\0';

	for (; src[i]; i++)
		res[i] = src[i];

	return (res);
}
