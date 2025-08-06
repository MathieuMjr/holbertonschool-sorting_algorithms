#include "sort.h"

/**
 * swap - swap a node with another
 * @node: a node to swap
 * @next: with the next one
 * @list: pointer to the head of the list
 *
 * Return:
 */
void swap(listint_t *node, listint_t *next, listint_t **list)
{
	listint_t *temp_prev;

	temp_prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = next;
	else
		*list = next;
	if (next->next != NULL)
		next->next->prev = node;
	node->next = next->next;
	node->prev = next;
	next->next = node;
	next->prev = temp_prev;
}

/**
 * insertion_sort_list - sort data in a
 * doubly linked list
 * @list: pointer to the head of the list
 *
 * Return:
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head_f = *list;
	listint_t *head_b;
	listint_t *next;
	listint_t *prev;

	while (head_f->next != NULL)
	{
		next = head_f->next;
		if (head_f->n > next->n)
		{
			swap(head_f, next, list);
			print_list(*list);
			head_b = next;
			while (head_b->prev != NULL)
			{
				prev = head_b->prev;
				if (prev->n > head_b->n)
				{
					swap(prev, head_b, list);
					print_list(*list);
				}
				else
					break;
			}
		}
		else
		{
			head_f = head_f->next;
		}
	}
}
