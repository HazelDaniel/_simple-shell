#ifndef ___MAIN_
#define ___MAIN_
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define __cp__(x, y) (_strcpy(&x, &y))
#define _al_len_(x) (_strlen(x) + (1))
char *_strtok(char *str, char *delim);
char *_trim(char *str);
int in_str(char c, char *str);
int is_print(char c);
char *_strcpy(char (*dest)[1024], char **src);
int _strcmp(char **str1_ptr, char **str2_ptr);
unsigned int _strlen(char *str);
void *_realloc(void *ptr, size_t old_size, size_t size);
#endif/*___MAIN_*/
