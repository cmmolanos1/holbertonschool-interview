#include "lists.h"

/**
* palindrome - check if a linked list is palindrome.
*
* @head: Pointer to the parent node.
* @n: Number of jumps until last node.
* Return: 1 if palindrome, otherwise 0.
*/
int palindrome(listint_t *head, int n)
{
	listint_t *left, *right;
	int i;

	if (head == NULL)
		return (1);

	left = head;
	right = left;


	for (i = 0; i < n; i++)
		right = right->next;

	if ((n == 0 || n == 1) && left->n == right->n)
		return (1);
	else if (left->n == right->n)
		return (palindrome(left->next, n - 2));
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
	int n = 0;
	listint_t *aux;

	if (head == NULL || *head == NULL)
		return (1);

	aux = *head;

	while (aux->next != NULL)
	{
		n++;
		aux = aux->next;
	}

	return (palindrome(*head, n));
}
