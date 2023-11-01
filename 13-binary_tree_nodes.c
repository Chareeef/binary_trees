#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the non-leaf nodes
 * @tree: pointer to the root of a binary tree
 * Return: number of non-leaf nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}
