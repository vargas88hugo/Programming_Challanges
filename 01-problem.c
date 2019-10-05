#include <stdio.h>
#include <stdlib.h>

void switching(int *a, int *b);
int max_length(int a, int b);

/**
 * main - program for the 3n + 1 problem
 * @argc: number of arguments
 * @argv: string of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int a, b, n, i = 0;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: ./c n1 n2\n");
		exit(EXIT_FAILURE);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	if (a > b)
		switching(&a, &b);

	n = max_length(a, b);

	printf("%d %d %d\n", atoi(argv[1]), atoi(argv[2]), n);

	return (0);
}

/**
 * switching - Function that switchs two variables
 * @a: integer one
 * @b: integer two
 */
void switching(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_length - Function that returns the maximun length of the conjeture
 * @a: beginning
 * @b: end
 * Return: the maximum length
 */
int max_length(int a, int b)
{
	int i = 0, j = 0, n;

	while (a != b)
	{
		a++;
		n = a;
		if (i > j)
			j = i;
		i = 1;
		while (n != 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = (n * 3) + 1;
			i++;
		}
	}
	if (i > j)
		j = i;

	return (j);
}
