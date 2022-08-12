#include "sort.h"
/**
 * insertion_sort_list - A function that sorts a doubly linked list
 * in ascending order using the insertion sort algorithm
 *
 * @list: The list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *back, *node;

	temp = *list;
	while (temp != NULL)
	{
		back = temp;
		temp = temp->next;

		if (temp->n < back->n)
		{
			node = malloc(sizeof(listint_t));
			if (temp->next == NULL)
				node->next = NULL;
			else
				node->next = temp->next;
			if (back->prev == NULL)
				node->prev = NULL;
			else
				node->prev = back->prev;
			temp->next = back;
			back->prev = temp;
			if (node->prev != NULL)
			{
				temp->prev = node->prev;
				(node->prev)->next = temp;
			}
			else
			{
				temp->prev = NULL;
				*list = temp;
			}
			if (node->next != NULL)
			{
				back->next = node->next;
				(node->next)->prev = back;
			}
			else	
				back->next = NULL;
			free(node);
			while (temp->prev != NULL)
				temp = temp->prev;
			print_list(temp);
		}
		if (temp->next == NULL)
			break;
	}
}
