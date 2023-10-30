#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root->left->right, 549);
    binary_tree_insert_left(root->left->right->right, 49);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %u\n", root->n, height);
    height = binary_tree_height(root->right);
    printf("Height from %d: %u\n", root->right->n, height);
    height = binary_tree_height(root->left->right);
    printf("Height from %d: %u\n", root->left->right->n, height);
    return (0);
}
