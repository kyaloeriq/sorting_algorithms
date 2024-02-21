/**
 * shell_sort - the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int gap, a, b, temp;

	for (gap = size / 2; gap > 0; gap /= 2)
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
		print _array(array, size);
	}
}
