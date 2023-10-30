#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if a node is a root
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a root, 0 if it's not or if it's NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->parent)
		return (0);
	else
		return (1);
}
