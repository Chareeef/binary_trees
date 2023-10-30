#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node
 * @parent: Pointer to the new node's parent
 * @value: Integer to store in the new node
 *
 * Return: The pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = NULL;

	return (new);
}
