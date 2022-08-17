#include "sort.h"

/**
 * cocktail_sort_list - A functiin that sorts a list into ascending
 * order using the cocktail sorting algorithm
 * @list: the unordered list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int flag = 1;
	listint_t *temp, *node, *front, *back;

	node = *list;

	if (node->next == NULL || node == NULL)
		return;

	while (flag == 1)
	{
		flag = 0;
	while (node->next != NULL)
	{
		if (node->n > (node->next)->n)
		{
			flag = 1;
			front = node->next;
			if (node == *list)
				*list = front;
			temp = malloc(sizeof(listint_t));
			if ((node->next)->next != NULL)
				temp->next = (node->next)->next;
			else
				temp->next = NULL;
			if (node->prev != NULL)
				temp->prev = node->prev;
			else
				temp->prev = NULL;
			front->next = node;
			node->prev = front;
			if (temp->prev != NULL)
			{
				front->prev = temp->prev;
				(temp->prev)->next = front;
			}
			else
				front->prev = NULL;
			if (temp->next != NULL)
			{
				node->next = temp->next;
				(temp->next)->prev = node;
			}
			else
				node->next = NULL;
			free(temp);
			print_list(*list);
			continue;
		}
		node = node->next;
	}

	while (node->prev != NULL)
	{
		if (node->n < (node->prev)->n)
		{
			flag = 1;
			back = node->prev;
			if (back == *list)
				*list = node;
			temp = malloc(sizeof(listint_t));
			if (back->prev != NULL)
				temp->prev = back->prev;
			else
				temp->prev = NULL;
			if (node->next != NULL)
				temp->next = node->next;
			else
				temp->next = NULL;
			back->prev = node;
			node->next = back;
			if (temp->prev != NULL)
			{
				node->prev = temp->prev;
				(temp->prev)->next = node;
			}
			else
				node->prev = NULL;
			if (temp->next != NULL)
			{
				back->next = temp->next;
 				(temp->next)->prev = back;
			}
			else
				back->next = NULL;
			free(temp);
			print_list(*list);
			continue;
		}
		node = node->prev;
	}}
}
