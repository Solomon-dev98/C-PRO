#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

char *_getenv(const char *name)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		name = environ[i];
		if (name == NULL)
		{
			return (NULL);
		}
	}

	return (name);
}
