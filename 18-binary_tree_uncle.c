#include "binary_trees.h"

/**
 * binary_tree_uncle - returns a node's uncle
 * @node: pointer to the node
 *
 * Return: the uncle's node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	return (node->parent->parent->left == node->parent ?
			node->parent->parent->right :
			node->parent->parent->left);
}
