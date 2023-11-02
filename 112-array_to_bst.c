#include "binary_trees.h"

/**
 * array_to_bst - creates a BST from array
 * @array: array of values
 * @size: size of the array
 *
 * Return: pointer to the root node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		if (bst_insert(&tree, array[i]) == NULL)
			return (NULL);
	}
	return (tree);
}
