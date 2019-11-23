#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main (int ac, char **av)
{
	int setres, i;

	setres = setenv("HOUSSEM", "edin93", 1);

	for (i = 0; environ[i]; i++)
	{
		printf("env[%d] = %s\n", i, environ[i]);
	}
	return (0);
}
