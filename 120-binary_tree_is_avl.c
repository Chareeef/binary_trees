#include "binary_trees.h"
#include <limits.h>

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
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l_height = 0, r_height = 0;

		l_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l_height > r_height) ? l_height : r_height);
	}
	return (0);
}

/**
 * is_avl - checks if a tree is avl
 * @tree: pointer to the tree
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int low, int high)
{
	if (tree)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		if (binary_tree_balance(tree) > 1 ||
				binary_tree_balance(tree) < -1)
			return (0);
		return (is_avl(tree->left, low, tree->n - 1) &&
				is_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
