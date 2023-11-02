#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Integer to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new;
	avl_t *curr_node, *next_parent;
	int balance;

	new = bst_insert(tree, value);

	if (!new)
		return (NULL);

	curr_node = new->parent;

	while (curr_node)
	{
		next_parent = curr_node->parent;
		balance = binary_tree_balance(curr_node);
		printf("curr_node = %d / balance = %d\n", curr_node->n, balance);

		if (balance > 1 && value < curr_node->left->n)
		{
			printf("R\n");
			binary_tree_rotate_right(curr_node);
		}
		else if (balance < -1 && value > curr_node->right->n)
		{
			printf("L\n");
			binary_tree_rotate_left(curr_node);
		}
		else if (balance > 1 && value > curr_node->left->n)
		{
			printf("RL\n");
			curr_node->left = binary_tree_rotate_left(curr_node->left);
			binary_tree_rotate_right(curr_node);
		}
		else if (balance < -1 && value < curr_node->right->n)
		{
			printf("LR\n");
			curr_node->right = binary_tree_rotate_right(curr_node->right);
			binary_tree_rotate_left(curr_node);
		}

		curr_node = next_parent;
	}

	return (new);
}

/**
 * bst_insert - inserts a node to a BST
 * @tree: double pointer to the tree
 * @value: value of the inserted node
 *
 * Return: pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *curr_node;

	if (tree)
	{
		curr_node = *tree;
		if (!curr_node)
		{
			new = binary_tree_node(curr_node, value);
			*tree = new;
			return (new);
		}
		while (curr_node)
		{
			if (value == curr_node->n)
				return (NULL);
			else if (value > curr_node->n)
			{
				if (curr_node->right)
					curr_node = curr_node->right;
				else
				{
					new = binary_tree_node(curr_node, value);
					curr_node->right = new;
					return (new);
				}
			}
			else if (value < curr_node->n)
			{
				if (curr_node->left)
					curr_node = curr_node->left;
				else
				{
					new = binary_tree_node(curr_node, value);
					curr_node->left = new;
					return (new);
				}
			}
		}
	}
	return (NULL);
}
