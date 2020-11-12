#include "list.h"
/**
 * add_node_end - adds a new node at the end of a double linked list
 * @list: pointer to a pointer of the start of the list
 * @str: string to be included in node
 * Return: address of the new element or NULL if it fails
 */
List *add_node_end(List **list, char *str)
{
	List *new, *last;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->str = strdup(str);
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->str = strdup(str);
	new->next = *list;
	(*list)->prev = new;
	new->prev = last;
	last->next = new;

	return (new);
}
/**
 * add_node_end - adds a new node at the end of a double linked list
 * @list: pointer to a pointer of the start of the list
 * @str: string to be included in node
 * Return: address of the new element or NULL if it fails
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *last;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->str = strdup(str);
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->str = strdup(str);
	new->next = *list;
	new->prev = last;

	last->next = (*list)->prev = new;
	*list = new;
	return (new);
}
