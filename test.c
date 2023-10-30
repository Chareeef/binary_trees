#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{

    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    printf("\nPre-order traversal :\n");
    binary_tree_preorder(root, &print_num);
    printf("\n\t***\n");

    printf("\nIn-order traversal :\n");
    binary_tree_inorder(root, &print_num);
    printf("\n\t***\n");

    printf("\nPost-order traversal :\n");
    binary_tree_postorder(root, &print_num);
    printf("\n\t***\n");

    return (0);
}
