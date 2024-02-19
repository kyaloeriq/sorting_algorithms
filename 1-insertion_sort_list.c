#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list using the Insertion sort
 * @list: list of integers 
 */
void insertion_sort_list(listint_t **list)
{
	size_t a, b;
	int temp;

	for (a = 0; a < b; a++)
	{
		if (b < a)
		{
			temp = a;
			a = b;
			b = temp;
			print_list (list);
		}
	}
}
