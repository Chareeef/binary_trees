#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t depth;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root->left->right, 549);
    binary_tree_insert_left(root->left->right->right, 49);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    depth = binary_tree_depth(root);
    printf("Depth from %d: %u\n", root->n, depth);
    depth = binary_tree_depth(root->right);
    printf("Depth from %d: %u\n", root->right->n, depth);
    depth = binary_tree_depth(root->left->right);
    printf("Depth from %d: %u\n", root->left->right->n, depth);
    depth = binary_tree_depth(root->left->right->right->left);
    printf("Depth from %d: %u\n", root->left->right->right->left->n, depth);
    return (0);
}
