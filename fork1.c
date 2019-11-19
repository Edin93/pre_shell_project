#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t parentId = getpid();
	pid_t childId;

	printf("parent process id = %u\n", parentId);
	childId = fork();
	if (childId == -1)
	{
		perror("ERROR\n");
		return (1);
	}
	printf("child process id = %u\n", childId);
	printf("CHECK AGAIN, parent process id = %u\n", parentId);
	return (0);
}
