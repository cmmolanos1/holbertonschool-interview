#include "binary_trees.h"
/**
 * sorted_array_to_avl - inserts sorted array elements to AVL tree
 * @array: pointer to sorted array
 * @size: number of elementss of array
 * Return: node to the root of AVL tree, otherwise NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t mid;
	avl_t *root;

	if (array == NULL || size < 1)
		return (NULL);

	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);

	mid = size / 2;

	root->n = array[mid];
	root->left = sorted_array_to_avl(array, mid);
	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

	if (root->left != NULL)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
}
