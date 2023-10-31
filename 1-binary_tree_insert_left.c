#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left child in
 * @value: Integer to store in the new node
 *
 * Return: The pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;

	new->left = parent->left;
	if (parent->left)
		parent->left->parent = new;
	parent->left = new;

	return (new);
}
