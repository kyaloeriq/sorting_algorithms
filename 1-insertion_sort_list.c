#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list using the Insertion sort
 * @list: list of integers 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = (*list)->next;
	listint_t *prev = cur->prev;
	int key = cur->b;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (cur != NULL)
	{
		while (prev != NULL && prev->b > key)
		{
			prev->next->b = prev->b;
			prev = prev->prev;
		}
		if (prev == NULL)
			(*list)->b = key;
		else
			prev->next->b = key;
		cur = cur->next;
		print_list(*list);
	}
}
