#include "binary_trees.h"

/**
 * bst_insert - inserts a node to a BST
 * @tree: double pointer to the tree
 * @value: value of the inserted node
 *
 * Return: pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	if (!tree)
		return (NULL);
	if (*tree == NULL)
	{
		new = binary_tree_node(*tree, value);
		if (!new)
			return (NULL);
		*tree = new;
		return (new);
	}
	if (value > (*new)->n)
	{
		if ((*new)->right)
			return bst_insert(&(*new)->right, value);
		new = binary_tree_node(*tree, value);
		if (!new)
			return (NULL);
		(*tree)->right = new;
		return (new);
	}
	if (value < (*new)->n)
	{
		if ((*new)->left)
			return bst_insert(&(*new)->left, value);
		new = binary_tree_node(*tree, value);
		if (!new)
			return (NULL);
		(*tree)->left = new;
		return (new);
	}
	return (NULL);
}
