#include <stdio.h>
#include <stdlib.h>

/**
 * draw_grid - Function that draws a Minesweeper
 * @width: width of the matrix
 * @height: height of the matrix
 * @ptr: grid to be drawed
 */
void draw_grid(int width, int height, char **ptr)
{
	int i, j;

	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{

		}
	}
}

/**
 * create_grid - Function that creates a multidimensional matrix
 * @width: width of the matrix
 * @height: height of the matrix
 * @ptr: grid to be drawed
 */
void create_grid(int width, int height, char **ptr)
{
	int i;

	ptr = malloc(sizeof(char *) * width);
	if (ptr == NULL)
	{
		printf("Malloc failed\n");
		exit(1);
	}

	for (i = 0; i < width; i++)
	{
		ptr[i] = malloc(sizeof(char) * height);
		if (ptr == NULL)
		{
			printf("Malloc failed\n");
			exit(1);
		}
	}
}

/**
 * main - program for Minesweeper problem
 * Return: 0 on success or -1 otherwise
 */
int main(void)
{
	int width = 0, height = 0;
	char **ptr = NULL;

	printf("Please enter the dimension of the matrix:\n");
	scanf("%d %d", &width, &height);

	create_grid(width, height, ptr);
	printf("%d %d\n", width, height);

	printf("Please enter safe squares are denoted by '.' and mine squares by '*'\n");

        draw_grid(ptr);
}
