#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *const argv[] = {"/bin/ls", "-l", "-1", NULL};
	char *const envp[] = {NULL};

	execve("/bin/ls", argv, envp);
	
	/* if execve fails, return -1 */

	perror("execve");

	return (1);
}
