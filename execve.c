#include <stdio.h>
#include <unistd.h>
/**
 */
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;

	printf("Before execve\n");

	if (execve(argv[1], argv+1, NULL) == -1)
	{
		perror("Error\n");
	}

	printf("execve got executed without errors.\n");

	return (0);
}
