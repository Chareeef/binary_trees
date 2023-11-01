#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotation
 * @tree: node to rotate
 *
 * Return: pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_node, *temp;

	if (!tree || !tree->right)
		return (NULL);
	right_node = tree->right;
	temp = right_node->left;
	tree->right = temp;
	right_node->parent = tree->parent;
	right_node->left = tree;
	if (temp)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = right_node;
	if (temp)
	{
		if (temp->right == tree)
			temp->right = right_node;
		else
			temp->left = right_node;
	}
	return (right_node);
}
