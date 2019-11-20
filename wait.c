/*get_exitstatus.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status;

	if (fork()== 0)
		printf("HC: hello from child\n");
	else
	{
		printf("HP: hello from parent\n");
		wait(&status);
		printf("CT: child has terminated\n");
	}
	printf("Bye\n");
	return (0);
}
