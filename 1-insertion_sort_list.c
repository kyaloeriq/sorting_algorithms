#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list using the Insertion sort
 * @list: double pointer to the head of the list 
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
		key = cur->n;
		prev = cur->prev;

		while (prev != NULL && prev->n > key)
		{
			prev->next->prev = prev->prev;
			if (prev->next != NULL)
				prev->prev->next = prev->next;
			prev->next = key_node;
			prev->prev = key_node->prev;
			key_node->prev = prev;
			if (prev->prev == NULL)
				*list = prev;
			else
				prev->prev->next = prev;
			print_list(*list);
			prev = prev->prev;
		}
		cur = cur->next;
	}
}
