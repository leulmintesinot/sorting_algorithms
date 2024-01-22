#include "sort.h"

/**
 * swap_nodes - swap two nodes in doubly-linked list
 * @head: pointer to the head
 * @a: first node to swap
 * @b: second node to swap
 */
void swap_nodes(listint_t **head, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if ((*a)->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*head = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - sorts doubly linked list using insertion sort
 * @list: pointer to head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *inserted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = temp)
	{		temp = iterator->next;
		inserted = iterator->prev;
		while (inserted != NULL && iterator->n < inserted->n)
		{
			swap_nodes(list, &inserted, iterator);
			print_list((const listint_t *)*list);
		}
	}
}
