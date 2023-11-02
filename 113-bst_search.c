#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: pointer to the node
 * @value: value to look for
 *
 * Return: pointer to the node containing the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n > value)
			return (bst_search(tree->left, value));
		else if (tree->n < value)
			return (bst_search(tree->right, value));
		else
			return ((bst_t *)tree);
	}
	return (NULL);
}
