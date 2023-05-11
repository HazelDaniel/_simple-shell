#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
char *_strtok(char *str, char *delim);
char *_trim(char *str);
int in_str(char c, char *str);
int is_print(char c);

int main(void)
{
	char *hello, *token, *hello0;
	// char *hello_test = "hello \tworld\t  how  \t  is\tit";
	char *hello_test0 = "  \t  hello world how is it";
	char *hello_test = "ls -l";

	hello = _trim(hello_test);
	hello0 = _trim(hello_test0);
	token = _strtok(hello, " \t");
	printf("token is :%s\n\n", token);
	token = _strtok(NULL, " \t");
	printf("token is :%s\n\n", token);
	token = _strtok(NULL, " \t");
	printf("token is :%s\n\n", token);
	token = _strtok(hello0, " \t");
	printf("token is :%s\n\n", token);
	token = _strtok(NULL, " \t");
	printf("token is :%s\n\n", token);
	// printf("text is :%s\n", hello);
	// printf("old text is : %s\n", hello_test);
	free (hello);

	return (0);
}
/**
	* _strtok - a re-implementation of
	* the strtok function.
	* converts input string to tokens
	* @str: parameter of type char *.
	* @delim: the delimiter
	* Return: char *.
*/
char *_strtok(char *str, char *delim)
{
	/*YOU ALWAYS WANNA PASS IN A TRIMMED STRING*/
	static int _index = 0;
	int i = 0, count = 0;
	static char org_buff[1024] = "";
	unsigned long int int_str;
	ptrdiff_t diff = (ptrdiff_t)str;

	if (str)
	{
		for (count = 0; str[count] && count < 1024; count++)
			org_buff[count] = str[count];
	}
	// char *hello_test = "hello \tworld\t  how  \t  is\tit";
	if (!org_buff[0])
		return (NULL);
	if (!str)
	{
		// printf("the current character :%c...\n", ((char *)int_str)[0]);
		// printf("the current string :%s\n", (char *)int_str);
		count = 0, i = 0;
		diff = (ptrdiff_t)(int_str);
		while (!in_str(((char *)int_str)[count], delim) && ((char *)int_str)[count])
			count++, i++;
		((char *)int_str)[count] = '\0';
		while (in_str(((char *)int_str)[++count], delim) && ((char *)int_str)[count])
			count++;
		_index += count;
		int_str += count;
		// printf("word count is : %d\n", i);
	}
	else
	{
	// char *hello_test = "hello \tworld\t  how  \t  is\tit";
		count = 0, i = 0;
		while (in_str(str[count], delim))
			count++;
		diff = (ptrdiff_t)(str + count);
		int_str = (unsigned long int)diff;
		while (!in_str(str[count], delim))
			count++;
		((char *)int_str)[count] = '\0', count++;
		while (in_str(str[count], delim) && str[count] != '\0')
			count++;
		_index = count, int_str += count;
		// printf("the next character :%c...\n", ((char *)int_str)[0]);
		// printf("the next string :%s\n", (char *)int_str);
	}
	return ((char *)diff);
}

/**
  * _trim - a function that trims
  * @str: the string to trim
  * Return: the trimmed string
 */
char *_trim(char *str)
{
	int pos_start = 0, i = 0, pos_end = strlen(str) - 1,
	stat = 0, sp_num = 0;
	char *sp_char = " \t", *res = NULL;

	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (!(in_str(str[i], sp_char)))
			break;
		if (stat == 0)
		{
			stat = 1;
			pos_start = i;
			while ((in_str(str[pos_start], sp_char)))
				pos_start++;
		}
		i++;
	}
	i = pos_end;

	for (; i >= 0 && in_str(str[i], sp_char); i--)
		;
	pos_end = i;

	res = malloc((pos_end - pos_start + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	for (i = 0, stat = pos_start; stat <= pos_end; stat++)
		res[i++] = str[stat];
	res[pos_end - pos_start + 1] = '\0';

	return (res);
}

/**
 * is_print - a function
 * that checks if a character is printable
 * @c: the character parameter
 * Return: int
 **/
int is_print(char c)
{
	return (c >= 33 && c < 127);
}

/**
  * in_str - a function that looks up
	* a character in a string and returns
	* a boolean integer if found
  * @c: parameter of type char .
  * @str: parameter of type char *.
  * Return: int .
 */
int in_str(char c, char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
