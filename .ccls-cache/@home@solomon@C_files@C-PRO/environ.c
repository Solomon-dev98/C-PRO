#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	while(*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
}
