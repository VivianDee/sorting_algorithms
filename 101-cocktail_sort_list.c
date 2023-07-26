#include "sort.h"

/**
* sort_forward - Sorts a doubly linked list in a
* forward direction
* @list: A doubly linked list
*
*/

void sort_forward(listint_t **list)
{
	listint_t *prev, *next, *node = *list, *temp;

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
			print_list(*list);
		}
		else
			node = node->next;
	}
}

/**
* sort_backwards - Sorts a doubly linked list in a
* backwards direction
* @list: A doubly linked list
*
*/
void sort_backwards(listint_t **list)
{
	listint_t *prev, *next, *node = *list, *temp;

	while (node->next)
		node = node->next;

	while (node->prev)
	{
		if (node->n < node->prev->n)
		{
			prev = node->prev;
			temp = node->prev->prev;
			next = node->next;

			if (temp)
				temp->next = node;
			else
				*list = node;

			node->prev = temp;

			if (next)
				next->prev = prev;
			else
				prev->prev = node;

			node->next = prev;
			prev->prev = node;
			prev->next = next;

			print_list(*list);
		}
		else
			node = node->prev;
	}
}


/**
*  check_list - Checks if a doubly linked list is sorted
* @list: A doubly linked list
*
* Return: 0 (Unsorted) or  1 (Sorted)
*/
int check_list(listint_t **list)
{
	listint_t *node = *list;

	while (node && node->next)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}

	return (1);
}


/**
* cocktail_sort_list- Sorts a doubly linked list
* using the Cocktail sort algorithm
* @list: A doubly linked list
*
*/

void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (1)
	{
		sort_forward(list);
		sort_backwards(list);
		if (check_list(list))
			break;
	}
}
