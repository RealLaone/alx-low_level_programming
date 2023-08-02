#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temp = *head;

	/* Allocate memory for new node */
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	/* Set data for new node */
	new->n = n;
	new->next = NULL;

	/* If list is empty, make new node the head */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	/* Traverse list until last node is reached */
	while (temp->next)
		temp = temp->next;

	/* Add new node to end of list */
	temp->next = new;

	return (new);
}
