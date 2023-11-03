#include "binary_trees.h"

/**
 * avl_sorted_insert - Insert a node from sorted array into AVL tree
 * @prec: The precedent node
 * @value: The value to insert into the AVL tree
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_sorted_insert(avl_t *prec, int value)
{
	avl_t *new = NULL;

	if (!prec)
		return (binary_tree_node(NULL, value));

	if (!prec->left)
	{
		new = binary_tree_node(NULL, value);
		if (!new)
			return (NULL);

		while (prec->parent)
			prec = prec->parent;

		new->left = prec;
		prec->parent = new;
	}
	else if (prec->left)
	{
		new = binary_tree_node(prec, value);
		prec->right = new;
	}

	return (new);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node, *root;
	size_t i;

	if (!array || size < 1)
		return (NULL);

	node = NULL;

	for (i = 0; i < size; i++)
	{
		node = avl_sorted_insert(node, array[i]);

		if (!node)
			return (NULL);
	}

	root = node;

	while (root->parent)
	{
		root = root->parent;
	}

	return (root);
}
