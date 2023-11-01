#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the non-leaf nodes
 * @tree: pointer to the root of a binary tree
 * Return: number of non-leaf nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;
	if (!tree)
		return (0);
	count += (tree->left || tree->right) ? 1 : 0;
	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);
}
