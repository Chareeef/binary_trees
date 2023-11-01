#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor
 * @tree: pointer to a node
 *
 * Return: balance factor, 0 if null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * recursive_height - Recursively compute the binary tree's height
 * @node: current node
 * @cumulative_h: cumulative height
 *
 * Return: The height of the binary tree
 */
size_t recursive_height(const binary_tree_t *node, size_t cumulative_h)
{
	size_t left_h, right_h;

	if (!node)
		return (cumulative_h - 1);

	left_h =  recursive_height(node->left, cumulative_h + 1);
	right_h = recursive_height(node->right, cumulative_h + 1);

	cumulative_h = left_h > right_h ? left_h : right_h;

	return (cumulative_h);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the binary tree, or 0 if tree is NULL or has no child
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursive_height(tree, 0));
}
