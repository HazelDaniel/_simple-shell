#ifndef ___MAIN_
#define ___MAIN_
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* MACROS */
#define __cp__(x, y) (_strcpy(&x, &y))
#define _al_len_(x) (_len_p((void **)x) + (1))

/* STRUCTURES AND DECLARATIONS */
struct command
{
	char *separator;
	char *command;
	int *status;
	struct command *next;
};

typedef struct command comm_t;

typedef comm_t *comm_list_t;

struct trash_env
{
	char *value;
	int *index;
	struct trash_env *next;
};

typedef struct trash_env trashenv_t;

extern char **environ;
extern char **new_environ;
extern comm_list_t *commands;
extern int comms_index;
extern trashenv_t *env_trash;


/* STRING UTILS */
char *_strtok(char *str, char *delim);
char **_splitstr(char *str, char *delim);
char *_trim(char *str);
int in_str(char c, char *str);
int is_print(char c);
char *_strcpy(char (*dest)[1024], char **src);
int _len_p(void **p);
char *_strddup(char *src);
int _strcmp(char **str1_ptr, char **str2_ptr);
unsigned int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdcat(char *dest, char *src);
int adj_char_num(char *str, char c, int i);
int first_oc(char *str, char c);
int is_start_str(char *strsub, char *strsup);


/* MEMORY UTILS */
void free_str_arr(char **str_arr, int is_dyn);
void **_realloc_ptr(void *ptr, size_t old_size, size_t size);
void *_realloc(void *ptr, size_t old_size, size_t size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void _memcpy_ptr(void **newptr, void **ptr, unsigned int size);

/* LIST UTILS */
void append_comm_list(comm_list_t list, int *index);
void append_comm(comm_list_t* list, char separator,
	const char* command, int status);
void print_comms(const comm_list_t list);
void print_comms_full();
trashenv_t *get_trash(trashenv_t *list, char *value);
void append_trash(trashenv_t *list, char *value, int index);
void remove_trash(trashenv_t *list, char *value);
void clear_trash(trashenv_t *list);

/* SPLIT UTILS */
void split_by_or(comm_list_t *c_list,
	char **all_c, char *curr_token);
void split_by_and(comm_list_t *c_list,
	char **raw_token, char *curr_token);
void split_by_and_or_order(comm_list_t *c_list,
	char **raw_token, char *curr_token);
void split_by_or_and_order(comm_list_t *c_list,
	char **raw_token, char *curr_token);

/* STATE UTILS */
void empty_state_buff(char *delim);

/* COMMAND HANDLERS */
int parse_to_commands(char *string);
void handle_parsed_commands(char **);
void free_commands();

/*_________________CORE___________________*/
/* ENVIRONMENT HANDLERS */
void _getAll_env();
char *_getenv(char *input);
int _setenv(char *input1, char *input2);
void _unsetenv(char *value);
void _copyenv();
void _freenv();


#endif/*___MAIN_*/
