#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
        char **execve_argv = NULL;
        int i;

        if (ac < 2)
        {
                perror("args less than 2\n");
                exit(EXIT_FAILURE);
        }

        /* Build the argv array for execve */
        execve_argv = malloc((ac + 1) * sizeof(char *));
        if (execve_argv == NULL)
        {
                perror("malloc failed\n");
                return (-1);
        }
        execve_argv[0] = "/bin/touch";

        for (i = 1; i < ac; i++)
                execve_argv[i] = av[i];
        execve_argv[ac] = NULL;

        char *const envp[] = {NULL};

        if (execve("/bin/touch", execve_argv, envp) == -1)
        {
                perror("execve\n");
                free (execve_argv);
                return (-1);
        }

        free(execve_argv);
        return (0);
}
