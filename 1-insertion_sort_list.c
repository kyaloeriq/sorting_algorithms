#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list using the Insertion sort
 * @list: list of integers 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *prev, *key_node;
	int key;
	cur = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (cur != NULL)
	{
		key_node = cur;
		key = cur->b;
		prev = cur->prev;

		while (prev != NULL && prev->b > key)
		{
			prev->next->b = prev->b;
			key_node = prev;
			prev = prev->prev;
		}
		if (prev == NULL)
		{
			(*list)->b = key;
			*list = key_node;
		}
		else
		{
			prev->next->b = key;
			key_node->n = prev->b;
		}
		cur = cur->next;
		print_list(*list);
	}
}
