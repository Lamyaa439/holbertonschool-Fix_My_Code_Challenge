#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index
 * @head: A pointer to the pointer of the first element
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;

	/* Case 1: Deleting the head node (index 0) */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	/* Traverse to find the node at the specified index */
	while (tmp != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	/* Case 2: Index out of range */
	if (tmp == NULL)
		return (-1);

	/* After finding the node 'tmp' at the correct index */

    /* 1. Repair the 'next' pointer of the PREVIOUS node */
    if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

    /* 2. Repair the 'prev' pointer of the NEXT node */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	
	free(tmp);
	return (1);
}
