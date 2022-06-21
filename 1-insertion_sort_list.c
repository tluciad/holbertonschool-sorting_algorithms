#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	new = (*list)->next;
	while (new != NULL)
	{
		temp = new->next;
		if (new->prev != NULL && new->prev->n > new->n)
		{
			new->prev->next = new->next;
			if (new->next != NULL)
				new->next->prev = new->prev;
			while (new->prev != NULL && new->prev->n > new->n)
			{
				new->next = new->prev;
				new->prev = new->prev->prev;
			}

			if (new->prev == NULL)
				*list = new;

			else
				new->prev->next = new;
			new->next->prev = new;
			print_list(*list);
		}
		new = temp;
	}
}
