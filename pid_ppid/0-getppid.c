#include <stdio.h>
#include <unistd.h>
/**
 * main - getppid.
 * Return: int.
 */
int main(void)
{
	pid_t id;

	id = getppid();
	printf("%u\n", id);
	return (0);
}
