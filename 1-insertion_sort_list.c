#include "sort.h"

/**
* insertion_sort_list - performs a sort a lil faster than bubble sort
* @list: double pointer to head of list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *outer = NULL, *inner = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	outer = *list;
	while (outer->next != NULL)
	{
		if (outer->n > outer->next->n)
		{
			inner = outer->next;
			list_swap(list, outer, outer->next);
			while (inner->prev != NULL)
			{
				if (inner->prev->n > inner->n)
					list_swap(list, inner->prev, inner);
				else
					break;
			}
		}
		else
			outer = outer->next;
	}
}

/**
* list_swap - swaps 2 listint_t nodes
* @list: head of list
* @left: left element to be swapped to the right
* @right: right element to be swapped to the left
*/
void list_swap(listint_t **list, listint_t *left, listint_t *right)
{
	if (left == *list)
		*list = right;
	if (left->prev != NULL)
		left->prev->next = right;
	if (right->next != NULL)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
	print_list(*list);
}
