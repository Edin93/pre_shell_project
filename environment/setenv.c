#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite);

struct dir
{
	char *name;
	char *value;
	struct dir *next;
};

typedef struct dir dir;

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

size_t print_list(dir *h)
{
	size_t s = 0;
	char *name, *value;

	while (h != NULL)
	{
		name = h->name;
		if (name != NULL)
		{
			printf("name = %s\n", name);
		}
		value = h->value;
		if (value != NULL)
		{
			printf("value = %s\n", value);
		}
		s++;
		h = h->next;
	}
	return (s);
}

char *concatconst(const char *s1, const char *s2)
{
        int len1 = 0, len2 = 0, lens_sum, i, j;
        char *str;

        while (s1[len1] != '\0')
                len1++;
        while (s2[len2] != '\0')
                len2++;

        lens_sum = len1 + len2;
        str = malloc(sizeof(char) * (lens_sum + 1));

        if (str == NULL)
                exit (1);

        for (i = 0; i < lens_sum; i++)
        {
		if (i < len1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len1];
        }
	str[lens_sum] = '\0';
        return (str);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_var;
	int ei;

	ei = 0;
	env_var = *(environ + ei);

	while (env_var != NULL)
	{
		if (strcmp(name, env_var) == 0)
		{
			if (overwrite != 0)
				*(environ + ei) = concatconst(concatconst(name, "="), value);
			return (0);
		}
		else
		{
			ei++;
			env_var = *(environ + ei);
		}
	}
	if (env_var == NULL)
	{
		*(environ + ei) = concatconst(concatconst(name, "="), value);
		ei++;
		*(environ + ei) = NULL;
		return (0);
	}
	return (-1);
}

int main (void)
{
	int r;

	r = _setenv("HOUSSEM", "EDDINE BEN KHALIFA", 1);
	printf("r = %d\n", r);
	return (0);
}
