#include "utils/main.h"
/**
 * main - the entry point into the program
 * Return: int
 **/
int main(void)
{
	char *token, hello_cpy[1024], *log_token;
	char *command_list = "\tpwd;ls || echo hello world ; alx-milestones && echo hello world ; ps && ls || head -n 1 || whoami";
	char *path_test = "/usr/bin/ls: /home/toughware/bin/mySubCypher:/usr/.local/share/tmp/google-chrome2";
	int cmp, i = 0, j = 0;
	cmdlist_t *comm_list = NULL, *comm;

	comm_list = malloc(100 + 1 * sizeof(cmdlist_t));
	if (!comm_list)
		return (1);
	i = 0;

	char *cmd_list = _trim(command_list), **all_commands = NULL;
	char *cmd_trim, *sub_cmd_trim, **all_c, **all_c2;


	//"\tpwd;ls || echo hello world ; alx-milestones && echo hello world ; ps && ls || head -n 1 || whoami";
	//"\tpwd;ls && echo hello world ; alx-milestones || echo hello world ; ps && ls && head -n 1 && whoami";
	all_commands = _splitstr(cmd_list, ";");
	if (!all_commands)
		return (1);

	for (i = 0; all_commands[i]; i++)
	{
		char *cmd_trim = _trim(all_commands[i]), *sub_cmd_trim = NULL;
		char **all_c = NULL, **all_c2 = NULL;

		if (in_str('|', cmd_trim) && in_str('&', cmd_trim))
		{
			if (first_oc(cmd_trim, '|') < first_oc(cmd_trim, '&'))
			{
				all_c = _splitstr(cmd_trim, "|");
				for (j = 0; all_c[j]; j++)
				{
					if (!in_str('&', all_c[j]))
						printf("or command=>%s\n", all_c[j]);
				}
				for (j =0; all_c[j]; j++)
				{
					if (in_str('&', all_c[j]))
					{
						sub_cmd_trim = _trim(all_c[j]);
						all_c2 = _splitstr(sub_cmd_trim, "&");
						for (j = 0; all_c2[j]; j++)
							printf("and command=>%s\n", all_c2[j]);
					}
				}
			}
			else
			{
				all_c = _splitstr(cmd_trim, "|");
				for (j =0; all_c[j]; j++)
				{
					if (in_str('&', all_c[j]))
					{
						sub_cmd_trim = _trim(all_c[j]);
						all_c2 = _splitstr(sub_cmd_trim, "&");
						for (j = 0; all_c2[j]; j++)
							printf("and command=>%s\n", all_c2[j]);
					}
				}
				for (j = 0; all_c[j]; j++)
				{
					if (!in_str('&', all_c[j]))
						printf("or command=>%s\n", all_c[j]);
				}
			}
		}
		else if (in_str('|', cmd_trim))
		{
			all_c = _splitstr(cmd_trim, "|");
			for (j = 0; all_c[j]; j++)
				printf("or command=>%s\n", all_c[j]);
		}
		else if (in_str('&', cmd_trim))
		{
			all_c = _splitstr(cmd_trim, "&");
			for (j = 0; all_c[j]; j++)
				printf("and command=>%s\n", all_c[j]);
		}
		else
		{
			printf("free command=>%s\n", all_commands[i]);
		}
		puts("===================================>");
		free(cmd_trim);
	}

	free(cmd_list);

	return (0);
}
