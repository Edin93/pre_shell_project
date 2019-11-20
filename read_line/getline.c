#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *lineptr = NULL;
	size_t s = 0;
	ssize_t r;

	printf("$ ");
	r = getline(&lineptr, &s, stdin);
	printf("%s", lineptr);
	printf("getline result is: %zu\n", r);
	free(lineptr);
	return (0);
}
