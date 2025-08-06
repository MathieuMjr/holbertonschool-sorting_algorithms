#include "sort.h"

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
 * swap_f - swap a node forward
 * @node: pointer to a node
 * @next: pointer to the next node
 *
 * Return:
 */
/*void swap_f(listint_t *node, listint_t *next)
{
	listint_t *temp_prev;

	temp_prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = next;
	if (next->next != NULL)
		next->next->prev = node;
	node->next = next->next;
	node->prev = next;
	next->next = node;
	next->prev = temp_prev;
}*/

/**
 * swap_b - swap a node backward
 * @prev: prev node of the current node
 * @list: pointer to the head of a list
 *
 * Return:
 */
/*void swap_b(listint_t *node, listint_t *prev, listint_t **list)
{
	listint_t *temp_next;

	if (prev->prev != NULL)
		prev->prev->next = node;
	else
		*list = node;
	if (node->next != NULL)
		node->next->prev = prev;
	temp_next = node->next;
	node->prev = prev->prev;
	node->next = prev;
	prev->prev = node;
	prev->next = temp_next;
}*/

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
			/*swap_f(head_f, next);*/
			swap(head_f, next, list);
			print_list(*list);
			head_b = next;
			while (head_b->prev != NULL)
			{
				prev = head_b->prev;
				if (prev->n > head_b->n)
				{
					/*swap_b(head_b, prev, list);*/
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
