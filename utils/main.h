#ifndef ___MAIN_
#define ___MAIN_
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
char *_strtok(char *str, char *delim);
char *_trim(char *str);
int in_str(char c, char *str);
int is_print(char c);
#endif/*___MAIN_*/
