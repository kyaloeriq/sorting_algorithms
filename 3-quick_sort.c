#include "sort.h"
/*
 * quick_sort - sorts an array of integers in ascending order using quicksort
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int pvt = array[size - 1];
	int temp;
	size_t a = 0;
	size_t b;

	if (size < 2)
		return;

	/*partitioning*/
	for (b = 0; b < size - 1; b++)
	{
		if (array[b] < pvt)
		{	/*swapping array[a] and array[b]*/
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			print_array(array, size);
			a++;
		}
	}
	/*swapping array[a] and pivot*/
	temp = array[a];
	array[a] = array[size - 1];
	array[size - 1] = temp;
	print_array(array, size);
	/*Recursive calls for the two partitions*/
	quick_sort(array, a);
	quick_sort(array + a + 1, size - a - 1);
}	
