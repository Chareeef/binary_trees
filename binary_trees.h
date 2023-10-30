#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/* Libraries */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Basic Binary Tree */

/**
 * struct binary_tree_s - Binary Tree node
 * @n: Integer to be stored in the node
 * @parent: Pointer to the node's parent
 * @left: Pointer to the node's left child
 * @right: Pointer to the node's right child
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree */

typedef struct binary_tree_s bst_t;

/* AVL Tree */

typedef struct binary_tree_s avl_t;

/* Max Heap Tree */

typedef struct binary_tree_s heap_t;

/* Main functions */


/* Helper functions */

void binary_tree_print(const binary_tree_t *);

#endif
