#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

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

int main (void)
{
	char *env_var;
	dir *node, *next_node;
	dir *head;
	int ei;

	ei = 0;
	env_var = *(environ + ei);

	while (env_var != NULL)
	{
		node = malloc(sizeof(dir));
		node->name = strdup(strtok(env_var, "="));
		node->value = strdup(strtok(NULL, "="));
		if (node == NULL)
		{
			exit (1);
		}
		if (ei == 0)
			head = node;
		next_node = malloc(sizeof(dir));
		if (next_node == NULL)
			exit (1);
		node->next = next_node;
		node = next_node;
		ei++;
		env_var = *(environ + ei);
	}
	node->next = NULL;
	print_list(head);

	return (0);
}
