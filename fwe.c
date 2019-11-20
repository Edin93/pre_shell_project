#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t c;
	int status, i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	while (i < 5)
	{
		c = fork();
		if (c == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			    perror("Error executing the command\n");
		}
		if (wait(&status))
			i++;
		else
		{
			printf("Error at status: %d\n", status);
			exit (EXIT_FAILURE);
		}
	}
	return (0);
}
