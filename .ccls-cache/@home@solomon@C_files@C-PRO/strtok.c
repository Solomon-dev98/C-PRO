#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "My name is solomon";
	const char *delim = " ";
	char *token;

	token = strtok(str, delim);

	while(token != NULL)
	{
		printf("Token = %s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);

}
