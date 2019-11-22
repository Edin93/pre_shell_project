#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("ENV adddress = %p\n", env);
	printf("ENVIRON address = %p\n", environ);

	return (0);
}
