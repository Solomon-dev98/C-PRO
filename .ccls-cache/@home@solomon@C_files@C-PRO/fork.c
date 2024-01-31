#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	/* fork returns the child ID to the parent and 0 to the child */
	pid = fork();
	if (pid == -1)
	{
		perror("error\n.");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		sleep(15);
		printf("child process: %u\n", getpid());
	}
	else
	{
		printf("parent process: %u\n", getpid());
	}
	return (0);
}
