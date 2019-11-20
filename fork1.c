#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t parent, child, chachild;

	parent = getpid();
	printf("%u parent ID\n", parent);

	child = fork();
	if (child == -1)
	{
		perror("Error\n");
		return (1);
	}
	chachild = fork();
	if (chachild == -1)
	{
		perror("Chachild Error\n");
		return (1);
	}

	printf("%u chachild ID\n", chachild);

	printf("%u child ID\n", child);

	return (0);
}
