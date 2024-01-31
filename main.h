#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LENGTH 1048
ssize_t _getline(char **linept, size_t *n, FILE *stream);
void _which(char *filename);
char *_strcat(char *dest, char *src);
#endif
