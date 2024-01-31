#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void print_dir(void)
{
	char *path = getenv("PATH");
	char *token;

	if (path == NULL)
	{
		fprintf(stdout, "%s\n", "PATH environment variable not found");
		return;
	}
	
	token = strtok(path, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}
