#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list using the
* Insertion sort algorithm
* @list: A doubly linked list
*
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list, *temp, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	while (node)
	{
		if (node->next && node->n > node->next->n)
		{
			prev = node->prev;
			temp = node->next->next;
			next = node->next;
			node->next = temp;
			if (temp)
				temp->prev = node;
			node->prev = next;
			next->next = node;
			next->prev = prev;
			if (prev)
				prev->next = next;
			else
				*list = next;
			node = *list;
			print_list(*list);
		}
		else
			node = node->next;
	}
}
