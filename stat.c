#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

int main(int ac, char **av)
{
	struct stat file_info;
	unsigned int i;

	if (ac < 2)
	{
		fprintf(stdout, "Usage: %s filepath\n", av[0]);
		return (1);
	}

	i = 1;
	
	while (av[i])
	{
		if (stat(av[i], &file_info) == 0)
		{
			fprintf(stdout, "%s\n", "Found");
		}
		else
		{
			fprintf(stdout, "%s\n", "Not Found");
		}
		i++;
	}

	return (0);
}
