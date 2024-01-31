#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *const argv[] = {"/bin/pwd", NULL};
	char *const envp[] = {NULL};

	if (execve("/bin/pwd", argv, envp) == -1)
	{
		perror("execve");
		return (1);
	}

	return (0);
}
