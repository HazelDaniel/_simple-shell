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
