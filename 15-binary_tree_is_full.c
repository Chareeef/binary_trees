#include "binary_trees.h"

/**
 * is_full - checks if a tree is full
 * @tree: pointer to a node
 *
 * Return: 1, 0 if tree is not full
 */
int is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if ((!tree->left && tree->right) || (tree->left && !tree->right) ||
			is_full(tree->left) == 0 ||
			is_full(tree->right) == 0)
		return (0);
	return (1);
}

/**
 * binary_tree_is_full - checks if tree is full
 * @tree: pointer to the root of the tree
 *
 * Return: 1, 0 if tree is null
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_full(tree));
}
