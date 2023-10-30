#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 if it's not or if it's NULL.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->right || node->left)
		return (0);
	else
		return (1);
}
