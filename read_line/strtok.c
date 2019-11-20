#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *arr[1024];
	int i = 0;
	char str[] = "Hello is it me you looking for?  I   can    see  it";

	arr[i] = strtok(str, " ");

	while ((arr[++i] = strtok(NULL, " ")) != NULL)
		;
	for (i = 0; arr[i] != NULL; i++)
		printf("%s\n", arr[i]);
	return (0);
}
