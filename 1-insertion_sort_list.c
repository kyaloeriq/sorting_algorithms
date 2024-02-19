#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list using the Insertion sort
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *prev, *key_node;

	cur = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (cur != NULL)
	{
		key_node = cur;
		prev = cur->prev;

		while (prev != NULL && prev->n > key_node->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = key_node;
			if (key_node->next != NULL)
				key_node->next->prev = prev;

			prev->next = key_node->next;
			key_node->prev = prev->prev;
			prev->prev = key_node;
			key_node->next = prev;

			if (key_node->prev == NULL)
				*list = key_node;
	
			print_list(*list);
			
			prev = key_node->prev;
		}
		cur = cur->next;
	}
}
