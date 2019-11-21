#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *s1, char *s2)
{
        int len1 = 0, len2 = 0, lens_sum, i;
        char *str;

	printf("Str 1 = %s\n", s1);
        printf("Str 2 = %s\n", s2);

        while (s1[len1] != '\0')
                len1++;
        while (s2[len2] != '\0')
                len2++;

        lens_sum = len1 + len2 + 1;
        str = malloc(sizeof(char) * (lens_sum + 1));

        if (str == NULL)
                exit (1);

        for (i = 0; i < lens_sum; i++)
        {
                if (i < len1)
                        str[i] = s1[i];
                if (i == len1)
                        str[i] = '/';
                else
                        str[i] = s2[i - (len1 + 1)];
		printf("hay ka3bit char: %c\n", str[i]);
        }
	str[i] = '\0';
	printf("fil concat: %s\n", str);
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

	tmp = concat("/bin","ls");

/*
	while (token != NULL)
	{
		tmp = concat(token, av[1]);
		if (stat(tmp, &statbuf) == 0)
		{
			printf("result = %s\n", tmp);
			break;
		}
		token = strtok(NULL, ":");
	}
*/
        return (0);
}
