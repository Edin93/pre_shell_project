#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *s1, char *s2)
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
int main(int ac, char *av[])
{
        char *env0, *env, *token, *tmp;
        int i;
        struct stat statbuf;

	env0 = getenv("PATH");
	env = strdup(env0);
	token = strtok(env, ":");

	for (i = 1; i < ac; i++)
	{
		while (token != NULL)
		{
			tmp = concat(concat(token, "/"), av[i]);
			if (stat(tmp, &statbuf) == 0)
			{
				printf("%s\n", tmp);
				break;
			}
			token = strtok(NULL, ":");
		}
	}
        return (0);
}
