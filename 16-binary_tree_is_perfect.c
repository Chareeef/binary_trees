#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the binary tree to measure the size
 *
 * Return: The size of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (!tree)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: Pointer to the root of the tree.
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: pointer to the tree
 *
 * Return: 1, 0 if tree is null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, expected_count, node_count;

	if (!tree)
		return (0);
	height = binary_tree_height(tree);
	expected_count = (1 << height) - 1;
	node_count = binary_tree_size(tree);

	return (expected_count == node_count ? 1 : 0);
}
