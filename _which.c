#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define MAX_LENGTH 1048

void _which(char *filename)
{
	char *token, *saveptr;
	char *path = getenv("PATH");
	char full_path[MAX_LENGTH];

	while (strtok_r(path, ":", &saveptr) != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			fprintf(stdout, "%s\n", full_path);
			return;
		}

		path = NULL;
	}

	fprintf(stdout, "%s not found in path\n", filename);
}
