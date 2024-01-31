#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int status;
	pid_t pid = fork();
	pid_t child_pid = wait(&status);

	if (pid == -1)
	{
		perror("Fork failed.\n");
		exit(EXIT_FAILURE);
	}

	if (pid > 0)
	{
		if (child_pid == -1)
		{
			perror("waitpid failed.\n");
			exit(EXIT_FAILURE);
		}
		
		if (WIFEXITED(status))
		{
			printf("child process %u exited with stattus %d\n", child_pid, WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			printf("child process %u exited with signal %d\n", child_pid, WTERMSIG(status));
		}
	}
	else
	{
		printf("child process: %u\n", getpid());
		exit(EXIT_SUCCESS);
	}
	
	return (0);
}
