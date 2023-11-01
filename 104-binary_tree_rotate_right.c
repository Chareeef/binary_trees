#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to right-rotate
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;
	binary_tree_t *temp;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;

	new_root->parent = tree->parent;
	tree->parent = new_root;

	temp = new_root->right;
	new_root->right = tree;
	tree->left = temp;

	if (temp)
		temp->parent = tree;

	return (new_root);
}
