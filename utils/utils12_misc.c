#include "main.h"

int find_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);

	return (num2);
}

int is_hwp(char c)
{
	if (c == 9 || c == 32)
		return (1);

	return (0);
}

int is_word(char c)
{
	if (c >= 65 && c <= 90 ||
	c >= 97 && c <= 122 || c == 95)
		return (1);

	return (0);
}

/**
 * last_oc - a function that returns
 * the last occurrence of a character
 * in a string
 * @str: the string
 * @c: the character
 * Return: int
 **/
int last_oc_of(char *str, char c)
{
	int count = _strlen(str) - 1;

	while (count >= 0 && str[count] != c)
		count--;

	if (str[count] == c)
		return (count);
	else
		return (-1);
}

int last_oc(int (* f)(char c), char *str)
{
	int count = _strlen(str) - 1;

	while (count >= 0 && !f(str[count]))
		count--;

	if (f(str[count]))
		return (count);
	else
		return (-1);
}

