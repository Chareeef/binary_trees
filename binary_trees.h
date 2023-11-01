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

binary_tree_t	*binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t	*binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t	*binary_tree_insert_right(binary_tree_t *parent, int value);
void		binary_tree_delete(binary_tree_t *tree);
int		binary_tree_is_leaf(const binary_tree_t *node);
int		binary_tree_is_root(const binary_tree_t *node);
void		binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void		binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void		binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void		binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
size_t		binary_tree_height(const binary_tree_t *tree);
size_t		binary_tree_depth(const binary_tree_t *tree);
size_t		binary_tree_size(const binary_tree_t *tree);
size_t		binary_tree_leaves(const binary_tree_t *tree);
size_t		binary_tree_nodes(const binary_tree_t *tree);
int		binary_tree_balance(const binary_tree_t *tree);
binary_tree_t	*binary_tree_sibling(binary_tree_t *node);
binary_tree_t	*binary_tree_uncle(binary_tree_t *node);
binary_tree_t	*binary_trees_ancestor(const binary_tree_t *first,
			const binary_tree_t *second);
binary_tree_t	*binary_tree_rotate_right(binary_tree_t *tree);
int		binary_tree_is_complete(const binary_tree_t *tree);
int		binary_tree_is_full(const binary_tree_t *tree);
int		binary_tree_is_perfect(const binary_tree_t *tree);
int		binary_tree_is_bst(const binary_tree_t *tree);
binary_tree_t	*binary_tree_rotate_left(binary_tree_t *tree);
bst_t		*bst_insert(bst_t **tree, int value);
avl_t		*avl_insert(avl_t **tree, int value);

/* Helper functions */

void		binary_tree_print(const binary_tree_t *);
void		print_num(int n);

/* Queue for binary trees problems */

/**
 * struct qnode - A queue's node
 * @bt_node: binary tree node
 * @next: Pointer to the next node
 */
typedef struct qnode
{
	binary_tree_t *bt_node;
	struct qnode *next;
} qnode;

/**
 * struct queue - A queue used for binary trees problems
 * @front: The queue's front
 * @rear: The queue's rear
 */
typedef struct queue
{
	qnode *front;
	qnode *rear;
} queue;

#endif
