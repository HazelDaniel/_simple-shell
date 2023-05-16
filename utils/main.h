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

/* STRUCTURES AND DECLARATIONS */
struct command
{
	char separator;
	char *command;
	int *status;
	struct command *next;
};

typedef struct command comm_t;

typedef comm_t *comm_list_t;

extern char **environ;
extern comm_list_t *commands;
extern int comms_index;


/* MEMORY UTILS */
void free_str_arr(char **str_arr, int is_dyn);
void *_realloc(void *ptr, size_t old_size, size_t size);

/* LIST UTILS */
void append_comm_list(comm_list_t list, int *index);
void append_comm(comm_list_t* list, char separator,
	const char* command, int status);
void print_comms(const comm_list_t list);
void print_comms_full();

#endif/*___MAIN_*/
