#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using Counting sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *cnt, *output;
	int max = array[0];

	if (size <= 1)
		return;

	/*Find the maximum element in the array*/
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/*Store count of individual elements*/
	cnt = (int *)malloc((max + 1) * sizeof(int));
	if (cnt == NULL)
		return;
	for (i = 0; i < size; i++)
		cnt[i] = 0;
	/*Store count of each element*/
	for (i = 0; i < size; i++)
		cnt[array[i]]++;
	/*Print the counting array*/
	for (i = 0; i < size; i++)
		printf("%lu: %d\n", (unsigned long)i, cnt[i]);
	/*Modify the count array such that each element at each index stores the sum of previous counts*/
	for (i = 1; i <= (size_t)max; i++)
		cnt[i] += cnt[i - 1];
	/*Output array to store the sorted array*/
	output = (int *)malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(cnt);
		return;
	}
	/*Build the output array*/
	for (i = size - 1; i < size; i--)
	{
		output[cnt[array[i]] - 1] = array[i];
			cnt[array[i]]--;
	}
	/*Copy the output array to array, so that array now contains the sorted numbers*/
	for (i = 0; i < size; i++)
		array[i] = output[i];
	/*Free dynamically allocated memory*/
	free(output);
	free(cnt);
}
