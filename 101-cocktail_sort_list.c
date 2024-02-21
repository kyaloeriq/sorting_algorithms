#include "sort.h"
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

		for (currt = currt->prev; currt->prev != NULL; currt = currt->prev)
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
