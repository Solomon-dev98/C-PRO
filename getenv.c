#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	unsigned int i = 0, j = 0;
	unsigned int name_len = 0;
	char *current_env;
	size_t current_len;

	while (name[j] != '\0')
	{
		name_len++;
		j++;
	}

	while (environ[i] != NULL)
	{
		current_env = environ[i];
		current_len =strcspn(current_env, "=");

		/* Check if the name matches and if the length is the same */
		if (current_len == name_len && strncmp(current_env, name, current_len) == 0)
		{
			/* Return the value part of the environment variable */
			return current_env + current_len + 1;
		}
	}
	return (NULL);
}
