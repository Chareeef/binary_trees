#include "binary_trees.h"


/**
 * insert_and_balance - Insert a node into avl tree then balance it if needed
 * @tree: Pointer to the root node of the AVL tree
 * @value: Integer to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *insert_and_balance(avl_t *tree, int value)
{
	avl_t *current, *new;
	int balance;

	current = tree;
	while (current)
	{
		if (value == current->n)
			return (NULL);
		else if (value > current->n)
		{
			if (current->right)
				current = current->right;
			else
			{
				new = create_node(value, current, 1);
				return (new);
			}
		}
		else if (value < current->n)
		{
			if (current->left)
				current = current->left;
			else
				return (create_node(value, current, -1));
		}
	}

	return (new);
}

*/

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Integer to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *current;
	avl_t *new;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new = NULL;
	current = *tree;
	if (value == current->n)
		return (NULL);
	else if (value < current->n)
	{
		new = avl_insert(&current->left, value);
		current->left = new;
	}
	else if (value > current->n)
	{
		new = avl_insert(&current->right, value);
		current->right = new;
	}

	return (new);
}
