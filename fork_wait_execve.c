#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int i = 5;
	while (i > 0)
	{
		int status;
		pid_t pid = fork();
		pid_t child_pid;

		if (pid == -1)
		{
			perror("fork failure.\n");
			exit(EXIT_FAILURE);
		}

		if (pid > 0)
		{
			child_pid = waitpid(pid, &status, 0);
			if (child_pid == -1)
			{
				perror("wait failure.\n");
				exit(EXIT_FAILURE);
			}

			if (WIFEXITED(status))
			{
				printf("child process %u exited with status %d\n", child_pid, WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status))
			{
				printf("child process %u exited with signal %d\n", child_pid, WTERMSIG(status));
			}
		}
		else
		{
			char *const argv[] = {"/bin/ls", "-l", "/tmp", "-1", NULL};
			char *const envp[] = {"PATH=/tmp", "USER=solomon", NULL};

			execve("/bin/ls", argv, envp);
			perror("execve.\n");
		}
		i--;
	}

	return (0);
}

