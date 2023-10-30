#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree's node
 * @tree: Pointer to the node to measure the depth 
 *
 * Return: The depth of the binary tree's node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;
	binary_tree_t *parent;

	if (!tree)
		return (0);

	depth = 0;

	parent = tree->parent;

	while (parent)
	{
		depth++;
		parent = parent->parent;
	}

	return (depth);
}
