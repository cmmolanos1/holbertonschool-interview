#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a node in a sorted linked list.
 * @head: pointer to head of list.
 * @number: number we want to insert.
 * Return: node inserted, otherwise NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *minor;
	listint_t *new;

	if (*head == NULL || head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	/* If new->n is smaller than head->n, replace head */
	if (new->n < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	else
	{
		/* Starting from head, search the node with n */
		/* greater than number */
		minor = *head;
		while (minor->next != NULL)
		{
			if (minor->next->n > number)
				break;
			minor = minor->next;
		}

		/* Connect minor -> new -> next */
		new->next = minor->next;
		minor->next = new;
		return (new);
	}
}
