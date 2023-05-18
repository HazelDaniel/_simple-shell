#include "main.h"

int is_start_str(char *strsub, char *strsup)
{
	int sub_len = _strlen(strsub), sup_len = _strlen(strsup);
	int i;

	if (sub_len > sup_len)
		return (0);

	for (i = 0; i < sub_len ; i++)
	{
		if (strsub[i] != strsup[i])
			break;
	}

	return (i == sub_len);
}

int is_end_str(char *strsub, char *strsup)
{
	int sub_len = _strlen(strsub), sup_len = _strlen(strsup);
	int i = 0;
	if (sub_len > sup_len)
		return (0);

	if (!sub_len)/* otherwise, sub_len = 0 and i = -1*/
		return (0);

	for (i = sub_len - 1; i >= 0; i--)
	{
		if (strsub[i] != strsup[sup_len - sub_len + i])
			break;
	}
	return (i == -1);
}

char * rm_tr_slash(char *str)
{
	int i;
	char *cpy = _strddup(str);

	for (i = 0; str[i]; i++)
		;
	if (str[i - 1] == '/')
		cpy[i - 1] = '\0';
	return (cpy);
}
