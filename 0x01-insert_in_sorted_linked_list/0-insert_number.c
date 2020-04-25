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

	if (head == NULL)
		return (NULL);

	/* Create and fill new node */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	/* If new is smaller than head, replace head */
	if (*head == NULL || new->n <= (*head)->n)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		minor = *head;
		while (minor->next != NULL && (minor->next->n < number))
			minor = minor->next;

		/* Connect minor -> new -> next */
		new->next = minor->next;
		minor->next = new;
	}
	return (new);
}
