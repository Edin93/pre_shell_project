#include <stdio.h>
#include <stdlib.h>
extern char **environ;

int main(int ac, char **av)
{
	int i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i]), i++;
	return (0);
}
