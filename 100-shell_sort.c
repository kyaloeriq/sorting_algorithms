#include "sort.h"
/**
 * shell_sort - the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;
	int temp;

	/* Calculates the initial gap using Knuth's sequence */
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Starts with the largest gap and work down to a gap of 1 */
	for (; gap > 0; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			temp = array[a];
			for (b = a; b >= gap && array[b - gap] > temp; b -= gap)
			{
				array[b] = array[b - gap];
			}
			array[b] = temp;
		}
		print_array(array, size);
	}
}
