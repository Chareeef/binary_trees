#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	    binary_tree_t *root;
	    size_t leaves;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root->left->right, 549);
	    binary_tree_insert_left(root->left->right, 9);
	    binary_tree_insert_left(root->left->right->right, 49);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    leaves = binary_tree_leaves(root);
	    printf("leaves from %d: %u\n", root->n, leaves);
	    leaves = binary_tree_leaves(root->right);
	    printf("leaves from %d: %u\n", root->right->n, leaves);
	    leaves = binary_tree_leaves(root->left->right);
	    printf("leaves from %d: %u\n", root->left->right->n, leaves);
	    leaves = binary_tree_leaves(root->left->right->right->left);
	    printf("leaves from %d: %u\n", root->left->right->right->left->n, leaves);
	    return (0);
}
