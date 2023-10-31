#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right child in
 * @value: Integer to store in the new node
 *
 * Return: The pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;

	new->right = parent->right;
	if (parent->right)
		parent->right->parent = new;
	parent->right = new;

	return (new);
}
