#include "list.h"
/**
 * add_node_end - adds a new node at the end of a double linked list
 * @list: pointer to a pointer of the start of the list
 * @str: string to be included in node
 * Return: address of the new element or NULL if it fails
 */
List *add_node_end(List **list, char *str)
{
	List *new, *last = *list;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->next = NULL;

	if (*list == NULL)
	{
		new->prev = NULL;
		*list = new;
		return (new);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new;
	new->prev = last;

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
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->next = *list;
	new->prev = NULL;

	if (*list != NULL)
		(*list)->prev = new;

	(*list) = new;

	return (new);
}
