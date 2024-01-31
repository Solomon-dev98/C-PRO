#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	unsigned int i;

	i = 0;

	if (env[i] != NULL)
	{
		printf("%p\n", env);
	}

	if (environ[i] != NULL)
	{
		printf("%p\n", environ);
	}

	return (0);
}
