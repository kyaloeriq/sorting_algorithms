#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	if (size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				/*Swap elements*/
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
