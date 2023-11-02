#include "binary_trees.h"

/**
 * in_order_successor - Find the in-order successor of an AVL tree node
 * @node: Pointer to the node to find the in-order successor
 *
 * Return: A pointer to the in-order successor, or NULL if it doesn't exist
 */
avl_t *in_order_successor(avl_t *node)
{
	avl_t *successor;

	if (node && node->right)
	{
		successor = node->right;

		while (successor->left)
			successor = successor->left;

		return (successor);
	}

	return (NULL);
}
/**
 * avl_balance - Balance an AVL tree
 * @root: Pointer to the root of the AVL
 *
 * Return: Pointer to new root node
 */
avl_t *avl_balance(avl_t *root)
{
	int balance;

	if (!root)
		return (NULL);

	balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
	{
		/* RR */
		return (binary_tree_rotate_right(root));
	}
	else if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		/* LR */
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	else if (balance < -1 && binary_tree_balance(root->right) >= 0)
	{
		/* LL */
		return (binary_tree_rotate_left(root));
	}
	else if (balance < -1 && binary_tree_balance(root->right) < 0)
	{
		/* RL */
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
/**
 * avl_remove - removes a node from AVL
 * @root: root of the AVL (pointer)
 * @value: value of the node to be deleted
 *
 * Return: new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else if (value == root->n)
	{
		/* 0 or 1 child */
		if (!root->left || !root->right)
		{
			temp = (root->right) ? root->right : root->left;
			if (!temp)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;

			free(temp);
		}
		/* 2 children */
		else
		{
			temp = in_order_successor(root);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	return (avl_balance(root));
}
