#include "main.h"

/**
  * _strcmp - a function that compares two strings
  * @str1_ptr: parameter of type char **
  * @str2_ptr: parameter of type char **
  * Return: an integer value
	* description: 0 if str1 == str2
	*              len(str1) - len(str2) if str1 != str2
	* warning: don't pass in the address of a null pointer
	*  you'll get the same behavior as the standard strcmp
	*  function
 */
int _strcmp(char **str1_ptr, char **str2_ptr)
{
	char *str1 = *str1_ptr, *str2 = *str2_ptr;
	int count, len1 = _strlen(str1), len2 = _strlen(str2);

	if (str1_ptr == str2_ptr)
		return (0);
	if (!str1 && !str2)
		return (0);
	if (!str1 && str2)
	{
		while (*str2++)
			count++;
		return (-count);
	}
	if (str1 && !str2)
	{
		while (*str1++)
			count++;
		return (count);
	}
	count = 0;
	while (*str1 == *str2)
		str1++, str2++;

	if (!*str1 && !*str2)
		return (0);
	if (*str1 && *str2)
		return (len1 + len2);
	if (*str1 && !*str2)
	{
		while (*str1++)
			count++;
		return (count);
	}
	if (!*str1 && *str2)
	{
		while (*str2++)
			count++;
		return (-count);
	}
	return (99);
}

/**
 * _strlen - a function that computes
 * the lenght of a string
 * @str: the string
 * Return: unsigned int
 **/
unsigned int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len])
		len++;

	return (len);
}

void *_realloc(void *ptr, size_t old_size, size_t size)
{
	char *res_tmp = NULL, *ptr_cp;
	void *res = NULL;
	int index = 0;

	if (size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		res = malloc(size);
		res_tmp = res;
		res_tmp[size - 1] = '\0';
	}
	else
	{
		if (size == old_size)
			return (ptr);

		ptr_cp = ptr;
		res = malloc(size);
		if (res == NULL)
		{
			free(ptr);
			return (res);
		}
		res_tmp = res;
		for (index = 0; index < size; index++)
		{
			if (size > old_size && index == old_size)
				break;
			res_tmp[index] = *ptr_cp++;
		}
		--index, res_tmp[index] = '\0';
		free(ptr);
	}

	return (res);
}
