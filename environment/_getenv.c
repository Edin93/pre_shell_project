#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _strlen - return string length.
 * @s: string pointer.
 * Return: 0
 */
int _strlen(char *s)
{
	int i = 0;

	while ((*(s + i) != '\0'))
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compare strings
 * @s1: string
 * @s2: string
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	int s1len = 0;
	int s2len = 0;
	int len = 0;
	int i;

	s1len = strlen(s1);
	s2len = strlen(s2);

	if (s2len >= s1len)
		len = s1len;
	else
		len = s2len;
	for (i = 0; i < len; i++)
	{
		if (s2[i] != s1[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

char *_getenv(const char *name)
{
	char *envar;
	int i;

	i = 0;
	envar = NULL;

	while (environ[i] != NULL)
	{
		envar = strtok(environ[i], "=");
		if (strcmp(envar, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (envar);
}

int main (void)
{
	char *result;

	result = _getenv("PATH");
	printf("result =\n%s\n", result);
	return (0);
}
