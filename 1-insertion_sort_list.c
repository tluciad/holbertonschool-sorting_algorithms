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

	new = *list;
	temp = *list;

	while (new != NULL)
	{
		new = new->next;
		while (temp->prev && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->next->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			temp->next->prev = temp;
			print_list(*list);
		}
		temp = new;
	}
}
