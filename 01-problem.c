/*
The 3n + 1 problem
Consider the following algorithm to generate a sequence of numbers. Start with an integer n. If n is even, divide by 2. If n is odd, multiply by 3 and add 1. Repeat this process with the new value of n, terminating when n = 1. For example, the following sequence of numbers will be generated for n = 22:
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
It is conjectured (but not yet proven) that this algorithm will terminate at n = 1 for every integer n. Still, the conjecture holds for all integers up to at least 1, 000, 000.
For an input n, the cycle-length of n is the number of numbers generated up to and including the 1. In the example above, the cycle length of 22 is 16. Given any two numbers i and j, you are to determine the maximum cycle length over all numbers between i and j, including both endpoints.
Input
The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers will be less than 1,000,000 and greater than 0.
Output
For each pair of input integers i and j, output i, j in the same order in which they appeared in the input and then the maximum cycle length for integers between and including i and j. These three numbers should be separated by one space, with all three numbers on one line and with one line of output for each line of input.
Sample Input
1 10
100 200
201 210
900 1000
Sample Output
1 10 20
100 200 125
201 210 89
900 1000 174
*/

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
