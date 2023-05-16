#include "utils/main.h"

/* GLOBAL DECLARATIONS */
comm_list_t *commands = NULL;
int comms_index;

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

	i = 0;

	char *cmd_list = _trim(command_list), **all_commands = NULL;
	char *cmd_trim, *sub_cmd_trim, **all_c, **all_c2;
	int comm_count = 0;


	//"\tpwd;ls || echo hello world ; alx-milestones && echo hello world ; ps && ls || head -n 1 || whoami";
	//"\tpwd;ls && echo hello world ; alx-milestones || echo hello world ; ps && ls && head -n 1 && whoami";
	all_commands = _splitstr(cmd_list, ";");
	if (!all_commands)
		return (1);

	commands = malloc(_al_len_(all_commands) * sizeof(comm_list_t));
	if (!commands)
		return (-1);
	commands[comm_count] = NULL;

	for (i = 0; all_commands[i]; i++)
	{
		char *cmd_trim = _trim(all_commands[i]), *sub_cmd_trim = NULL;
		char **all_c = NULL, **all_c2 = NULL;
		comm_list_t c_list = NULL, sentinel = NULL;
		int index = 0, k = 0;


		if (in_str('|', cmd_trim) && in_str('&', cmd_trim))
		{
			if (first_oc(cmd_trim, '|') < first_oc(cmd_trim, '&'))
			{
				all_c = _splitstr(cmd_trim, "|");
				for (j = 0; all_c[j]; j++)
				{
					if (!in_str('&', all_c[j]))
					{
						append_comm(&c_list, '|', all_c[j], 0);
					}
				}
				for (j =0; all_c[j]; j++)
				{
					if (in_str('&', all_c[j]))
					{
						sub_cmd_trim = _trim(all_c[j]);
						all_c2 = _splitstr(sub_cmd_trim, "&");
						for (j = 0; all_c2[j]; j++)
						{
							append_comm(&c_list, '&', all_c2[j], 0);
						}
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
						{
							append_comm(&c_list, '&', all_c2[j], 0);
						}
					}
				}
				for (j = 0; all_c[j]; j++)
				{
					if (!in_str('&', all_c[j]))
					{
						append_comm(&c_list, '|', all_c[j], 0);
					}
				}
			}
		}
		else if (in_str('|', cmd_trim))
		{
			all_c = _splitstr(cmd_trim, "|");
			for (j = 0; all_c[j]; j++)
			{
				append_comm(&c_list, '|', all_c[j], 0);
			}
		}
		else if (in_str('&', cmd_trim))
		{
			all_c = _splitstr(cmd_trim, "&");
			for (j = 0; all_c[j]; j++)
			{
				append_comm(&c_list, '&', all_c[j], 0);
			}
		}
		else
		{
			append_comm(&c_list, '\0', all_commands[i], 0);
		}

		append_comm_list(c_list, &comms_index);
		free(cmd_trim);
	}
	print_comms_full();
	printf("the total commands list in the commands table :%d\n", _len_p((void **)commands));

	free(cmd_list);

	return (0);
}

