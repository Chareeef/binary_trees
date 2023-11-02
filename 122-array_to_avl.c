#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t i, j;

	if (!array || size == 0)
		return (NULL);

	root = NULL;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		if (j == i)
		{
			if (!avl_insert(&root, array[i]))
				return (NULL);
		}
	}

	return (root);
}
