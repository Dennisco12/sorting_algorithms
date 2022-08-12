#include "sort.h"
/**
 * insertion_sort_list - A function that sorts a doubly linked list
 * in ascending order using the insertion sort algorithm
 *
 * @list: The list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *back, *temp;

	node = *list;
	while (node != NULL)
	{
		back = node;
		node = node->next;

		if (node->n < back->n)
		{
			temp = malloc(sizeof(listint_t));
			if (node->next == NULL)
				temp->next = NULL;
			else
				temp->next = node->next;
			if (back->prev == NULL)
				temp->prev = NULL;
			else
				temp->prev = back->prev;
			node->next = back;
			back->prev = node;
			if (temp->prev != NULL)
			{
				node->prev = temp->prev;
				(temp->prev)->next = node;
			}
			else
			{
				node->prev = NULL;
				*list = node;
			}
			if (temp->next != NULL)
			{
				back->next = temp->next;
				(temp->next)->prev = back;
			}
			else
				back->next = NULL;
			free(temp);
			while (node->prev != NULL)
				node = node->prev;
			print_list(node);
		}
		if (node->next == NULL)
			break;
	}
}
