#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - prints $, wait for user to enter command, prints it on the next line
 * Return: int.
 */
int main(void)
{
	char **lineptr;
	size_t *n;
	ssize_t r;
	size_t s = 0;

/*	n = &s;
	lineptr = malloc(sizeof(char) * (*n));
*/

	printf("$ ");
	r = getline(lineptr, &s, stdin);
	printf("%s", *lineptr);
	printf("Number of chars = %zu\n", r);
	return (0);
}
