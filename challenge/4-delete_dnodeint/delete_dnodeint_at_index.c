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
	unsigned int i;

	/* 1. Safety check: does the list even exist? */
	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;

	/* 2. Case: Deleting the very first node */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	/* 3. Traverse to the node we want to delete */
	for (i = 0; tmp != NULL && i < index; i++)
	{
		tmp = tmp->next;
	}

	/* 4. Case: Index is out of bounds */
	if (tmp == NULL)
		return (-1);

	/* 5. The Bridge: Re-link the neighbors before freeing */
	/* Point the PREVIOUS node's 'next' to the node AFTER tmp */
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

	/* Point the NEXT node's 'prev' back to the node BEFORE tmp */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
