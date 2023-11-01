#include "binary_trees.h"

/**
 * binary_tree_sibling - returns the sibling of a node
 * @node: node to look for its sibling
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->right
			|| !node->parent->left)
		return (NULL);
	return (node->parent->left == node ? node->parent->right
			: node->parent->left);
}
