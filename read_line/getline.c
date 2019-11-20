#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *lineptr = NULL;
	size_t s = 0;

	printf("$ ");
	getline(&lineptr, &s, stdin);
	printf("%s", lineptr);
	free(lineptr);
	return (0);
}
