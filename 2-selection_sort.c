#include "sort.h"
/*
 * selection_sort - sorts an array of integers in using Selection sort
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	while (a = 0; a < size; a++)
	{
		while (b = 0; b < a; b++)
		{
			temp = a;
			a = b;
			b = temp;
			print_array(b);
		}
	}
}
