#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t mypid;

	mypid = getppid();

	printf("%u\n", mypid);

	return (0);
}
