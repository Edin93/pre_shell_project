#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/* getline vars */
	char *lineptr = NULL;
	size_t s = 0;
	ssize_t chars_num; /* number of characters, to store getline result */

	/* strtok vars */
	char *token;
	int i = 0;
	char **words;

	/* execve vars */
	pid_t c;
	int status, i = 0;

	printf("$ ");
	getline(&lineptr, &s, stdin);

	token = strtok(lineptr, " \n");
	words = malloc(sizeof(char *));

	while (token != NULL)
	{
		words = realloc(words, sizeof(char *) * (i + 1));
		*(words + i) = strdup(token);
		i++;
		token = strtok(NULL, " \n");
	}

	for (i = 0; words[i] != NULL; i++)
		printf("%s\n", words[i]);

	free(lineptr);
	return (0);
}
