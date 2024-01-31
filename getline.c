#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t chars_read;

	while (1)
	{
		printf("$ ");
		chars_read = _getline(&line, &n, stdin);
		if (chars_read == -1)
		{
			printf("Error reading line.\n");
			free(line);
			return (-1);
		}
		printf("%s\n", line);
	}
	free(line);
	return (0);
}
