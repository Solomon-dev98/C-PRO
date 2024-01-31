#include <stdio.h>
#include <string.h>

int main(void)
{
	char **str = "Jesus Loves you";
	char *delim = " ";
	char *tok = NULL;

	tok = strtok(*str, delim);
	while (tok != NULL)
	{
		printf("tok = %s\n", tok);
		tok = strtok(NULL, delim);
	}

	return (0);
}
