#include "binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 64);
	root->left->left = binary_tree_node(root->left, 32);
	binary_tree_print(root);
	printf("Rotate-right %d\n", root->n);
	root = binary_tree_rotate_right(root);
	binary_tree_print(root);
	printf("\n");

	root->left->left = binary_tree_node(root->left, 20);
	root->left->right = binary_tree_node(root->left, 56);
	binary_tree_print(root);
	printf("Rotate-right %d\n", root->n);
	root = binary_tree_rotate_right(root);
	binary_tree_print(root);
	return (0);
}
