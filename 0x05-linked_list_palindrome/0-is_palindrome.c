#include "lists.h"

/**
* palindrome - check if a linked list is palindrome.
*
* @head: Pointer to the parent node.
* @tail: Number of jumps until last node.
* Return: 1 if palindrome, otherwise 0.
*/
int palindrome(listint_t *head, listint_t *tail)
{
	listint_t *left, *right, *aux;

	if (head == NULL)
		return (1);

	left = head;
	right = tail;
	aux = left;

	if ((left == right || left->next == right) && left->n == right->n)
		return (1);
	else if (left->n == right->n)
	{
		while (aux->next != right)
			aux = aux->next;
		return (palindrome(left->next, aux));
	}
	else
		return (0);
}
/**
* is_palindrome - check if a linked list is palindrome.
*
* @head: Pointer to the parent node.
* Return: 1 if palindrome, otherwise 0.
*/
int is_palindrome(listint_t **head)
{
	listint_t *aux;

	if (head == NULL || *head == NULL)
		return (1);

	aux = *head;

	while (aux->next != NULL)
		aux = aux->next;

	return (palindrome(*head, aux));
}
