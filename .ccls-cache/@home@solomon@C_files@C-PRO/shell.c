#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARG 64

ssize_t _getline(char **linept, size_t *n, FILE *stream);
int main(void)
{
	char input[MAX_INPUT];

	while (1)
	{
		char *line = NULL;
		size_t n = 0;
		ssize_t char_read;
		char *argv[MAX_ARG];
		char *token = NULL;
		int status, i = 0;

		/* read user input and check if nothing was read */

		fprintf(stdout, "%s", "#My_shell$ ");
		char_read = _getline(&line, &n, stdin);
		if (char_read == -1)
		{
			perror("error.\n");
			free(line);
			exit(EXIT_FAILURE);
		}

		/* exit the shell if user enters exit */

		if (strcmp(line, "exit") == 0)
			break;
		/* fork a child process and check if fork was successful */
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork failure.\n");
			free(line);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			/* child process: tokenize to get command and its path */
			token = strtok(line, " \t\n");
			while (token != NULL && i < MAX_ARG - 1)
			{
				argv[i] = token;
				token = strtok(NULL, "  \t\n");
				i++;
			}
			argv[i] = NULL;

			if (execvp(argv[0], argv) == -1)
			{
				perror("execvp failure\n");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* parent process */
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid failure.\n");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		free(line);
	}

	return (0);
}
