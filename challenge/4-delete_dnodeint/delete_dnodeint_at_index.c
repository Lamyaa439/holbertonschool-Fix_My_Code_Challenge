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

	/* Case 3: Deleting a node in the middle or at the end */
	/* Link the previous node to the next node */
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

	/* Link the next node back to the previous node */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
