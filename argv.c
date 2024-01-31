#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	(void)ac;

	int i = 1;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
