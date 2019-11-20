#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *lineptr = NULL;
	size_t s = 0;
	ssize_t chars_num; /* number of characters, to store getline result */

	printf("$ ");
	chars_num = getline(&lineptr, &s, stdin);
	while (chars_num >= 0)
	{
		printf("%s", lineptr);
		chars_num = getline(&lineptr, &s, stdin);
	}
	free(lineptr);
	return (0);
}
