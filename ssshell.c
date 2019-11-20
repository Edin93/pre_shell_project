#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - runs commands with their full path, without any argument.
 * @ac: arguments count.
 * @av: arguments vector.
 * @envp: environment.
 * Return: int.
 */
int main (int ac, char *av[], char *envp[])
{
	ssize_t size;
	size_t n = ;

	size = getline(lineptr, &n, NULL);
	printf("$ ");
}
