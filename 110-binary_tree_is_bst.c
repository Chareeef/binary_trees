#include "binary_trees.h"

/**
 * free_queue - free a queue
 * @q: Pointer to the queue
 */
void free_queue(queue *q)
{
	qnode *current, *temp;

	if (!q)
		return;

	current = q->front;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	free(q);
}
/**
 * enqueue - Add a node to the queue
 * @q: Pointer to the queue
 * @bt_node: binary tree node
 *
 * Return: Pointer to the new node.
 */
qnode *enqueue(queue *q, binary_tree_t *bt_node)
{
	qnode *new;

	if (!q)
		return (NULL);

	new = malloc(sizeof(qnode));
	if (!new)
	{
		free_queue(q);
		return (NULL);
	}

	new->bt_node = bt_node;
	new->next = NULL;

	if (!q->front)
	{
		q->front = new;
		q->rear = new;
		return (new);
	}

	q->rear->next = new;
	q->rear = new;
	return (new);
}

/**
 * dequeue - Dequeue a node from the queue
 * @q: Pointer to the queue
 *
 * Return: Pointer to removed node.
 */
binary_tree_t *dequeue(queue *q)
{
	qnode *temp;
	binary_tree_t *bt_node;

	if (!q)
		return (NULL);
	if (!q->front)
		return (NULL);

	temp = q->front;
	bt_node = temp->bt_node;

	if (q->rear == q->front)
		q->rear = NULL;

	q->front = temp->next;

	free(temp);
	return (bt_node);
}

/**
 * fill_queue - Fill the queue to check if a tree is a bst
 * @q: Pointer to the queue
 * @tree: Pointer to the root node of the binary tree
 */
void fill_queue(queue *q, binary_tree_t *tree)
{
	if (!q || !tree)
		return;

	fill_queue(q, tree->left);
	enqueue(q, tree);
	fill_queue(q, tree->right);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if it's a bst, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	queue *q;
	qnode *current;

	if (!tree)
		return (0);

	q = malloc(sizeof(queue));
	if (!q)
		return (0);

	q->front = NULL;
	q->rear = NULL;

	fill_queue(q, (binary_tree_t *) tree);

	current = q->front;
	while (current)
	{
		if (current->next &&
			current->bt_node->n >= current->next->bt_node->n)
		{
			return (0);
		}

		current = current->next;
	}

	free_queue(q);

	return (1);
}
