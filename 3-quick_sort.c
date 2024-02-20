#include "sort.h"
/*
 * quick_sort - sorts an array of integers in ascending order using the sort
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int pvt;
	size_t cur, prev, next;

	while (pvt < cur)
	{
		cur->next = pvt;
		pvt = cur->prev;
		cut->prev = cur->next;
	}
	print_array(array, size);
}	
