#ifndef ___MAIN_
#define ___MAIN_
#include <stddef.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/* MACROS */
#define __cp__(x, y) (_strcpy(&x, &y))
#define _al_len_(x) ((_len_p((void **)x)) + (1))

/* STRUCTURES AND DECLARATIONS */
typedef struct command
{
	char *separator;
	char *command;
	int *status;
	struct command *next;
} comm_t;

typedef comm_t *comm_list_t;

typedef struct trash_env
{
	char *value;
	int *index;
	struct trash_env *next;
} trashenv_t;


typedef struct var_env
{
	char *value;
	struct var_env *next;
}	var_t;

typedef struct path_dir
{
	char *dir;
	struct path_dir *next;
} pathdir_t;

typedef struct alias
{
	char *value;
	struct alias *next;
} alias_t;

typedef struct wtok
{
	int check_points[1024];
	char vals[1024];
} wtok_t;

extern char **environ;
extern char **new_environ;
extern comm_list_t *commands;
extern int comms_index;
extern trashenv_t *env_trash;
extern pathdir_t *path_list;
extern alias_t *aliases;
extern var_t *variables;


/* STRING UTILS */
char *_strtok(char *str, char *delim);
char **_splitstr(char *str, char *delim);
char *_trim(char *str);
int in_str(char c, char *str);
int is_print(char c);
char *_strcpy(char (*dest)[1024], char **src);
int _len_p(void **p);
char *_strddup(char *src);
int _strcmp(char *str1, char *str2);
unsigned int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdcat(char *dest, char *src);
int adj_char_num(char *str, char c, int i);
int first_oc_of(char *str, char c);
int first_oc(int (* f)(char c), char *str);
int is_start_str(char *strsub, char *strsup);
int is_end_str(char *strsub, char *strsup);
char * rm_tr_slash(char *str);
char *join_list(char **list);
char **word_tok(char *str);
wtok_t *gen_tok(char *str);


/* MEMORY UTILS */
void free_str_arr(char **str_arr, int is_dyn);
void **_realloc_ptr(void *ptr, size_t old_size, size_t size);
void *_realloc(void *ptr, size_t old_size, size_t size);
void _memcpy(void *ptr, const void *newptr, unsigned int size);
void _memcpy_ptr(void **ptr, void **newptr, unsigned int size);

/* LIST UTILS */
void append_comm_list(comm_list_t list, int *index);
void append_comm(comm_list_t* list, char separator,
	const char* command, int status);
void print_comms(const comm_list_t list);
void print_comms_full();
trashenv_t *get_trash(trashenv_t *list, char *value);
void append_trash(char *value, int index);
void remove_trash(trashenv_t *list, char *value);
void clear_trash(trashenv_t *list);
void print_trash(trashenv_t *list);
trashenv_t *pop_trash();
pathdir_t *linkpath(char *path);
void append_path(char *value);
void print_path();

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

/* PATH HANDLERS */
char *_trace(char *input);

/* INPUT HANDLERS */
ssize_t _getline(char **line_addr, size_t *n, FILE *stream);

/* ALIAS HANDLERS */
char *_getalias(char *input);
char *_setalias(char *input);
char *alias(char *input);
void free_aliases(alias_t *list);
void print_aliases();

/* SHELL VARIABLES */
void _getall_vars();
char *_getvar(char *input);
char *_setvar(char *input);
void free_vars(var_t *list);
char *lookup_var(char *input);
char *expand(char *input);


/* MISC */
int find_max(int num1, int num2);
int is_word(char c);
int is_hwp(char c);
int is_print(char c);
int last_oc_of(char *str, char c);
int last_oc(int (* f)(char c), char *str);

#endif/*___MAIN_*/
