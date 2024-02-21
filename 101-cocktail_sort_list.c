#include "sort.h"

void swap_nodes(listint_t **left, listint_t **right, listint_t **list);

/**
 * cocktail_sort_list - sorts a doubly linked list using Cocktail shaker sort
 * @list: list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	int swppd;
	listint_t *currt;

	swppd = 0;


	if (list == NULL || *list == NULL)
		return;

	do
	{
		for (currt = *list; currt->next != NULL; currt = currt->next)
		{
			if (currt->n > currt->next->n)
			{
				swap_nodes(&currt, &(currt->next), list);
				print_list(*list);
				swppd = 1;
			}
		}
		if (!swppd)
			break;

		for (; currt->prev != NULL; currt = currt->prev)
		{
			if (currt->n < currt->prev->n)
			{
				swap_nodes(&(currt->prev), &currt, list);
				print_list(*list);
				swppd = 1;
			}
		}
	} while (swppd);
}
void swap_nodes(listint_t **left, listint_t **right, listint_t **list)
{
	listint_t *temp;
	
	temp = *left;
	*left = *right;
	*right = temp;

	if ((*left)->prev == NULL)
		*list = *left;
	if ((*right)->next == NULL)
		*list = *right;

	if ((*left)->prev != NULL)
		(*left)->prev->next = *left;
	if ((*right)->next != NULL)
		(*right)->next->prev = *right;

	temp = (*left)->prev;
	(*left)->prev = (*right)->prev;
	(*right)->prev = temp;

	temp = (*left)->next;
	(*left)->next = (*right)->next;
	(*right)->next = temp;
}
