#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints all the arguments, without using ac (arguments count).
 * @ac: arguments count.
 * @av: arguments vector.
 * Return: int.
 */
int main(int ac, char **av)
{
	int i = 0;

	(void)ac;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
