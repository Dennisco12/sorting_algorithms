#include "sort.h"
/**
 * insertion_sort_list - A function that sorts a doubly linked list
 * in ascending order using the insertion sort algorithm
 *
 * @list: The list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *back, *temp, *temp2;

	node = *list;
	while (node != NULL)
	{
		back = node;
		node = node->next;

		if (node->n < back->n)
		{
			if (node->next != NULL)
				temp = node->next;
			else
				temp = NULL;

			if (back->prev == NULL)
				temp2 = NULL;
			else
				temp2 = back->prev;
			node->next = back;
			back->prev = node;
			if (temp2 != NULL)
			{
				node->prev = temp2;
				temp2->next = node;
			}
			else
			{
				node->prev = NULL;
				*list = node;
			}
			if (temp != NULL)
			{
				back->next = temp;
				temp->prev = back;
			}
			else
				back->next = NULL;
			print_list(*list);
			while (node->prev != NULL)
				node = node->prev;
		}
		if (node->next == NULL)
			break;
	}
}
