#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *lineptr;
	size_t s = 10;

	printf("$ ");
	getline(&lineptr, &s, stdin);
	printf("%s", lineptr);
	return (0);
}
