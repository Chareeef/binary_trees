#include "binary_trees.h"

/**
 * init_queue - initialize a queue
 *
 * Return: Pointer to the new queue
 */
queue *init_queue(void)
{
	queue *q;

	q = malloc(sizeof(queue));
	if (!q)
		return (NULL);

	q->front = NULL;
	q->rear = NULL;

	return (q);
}

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
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if it is complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *q, *nodes;
	qnode *current;

	if (!tree)
		return (0);

	q = init_queue();
	nodes = init_queue();

	enqueue(q, (binary_tree_t *) tree);

	while (q->front)
	{
		if (q->front->bt_node)
		{
			enqueue(q, q->front->bt_node->left);
			enqueue(q, q->front->bt_node->right);
		}

		enqueue(nodes, dequeue(q));
	}

	current = nodes->front;

	while (current)
	{
		if (current->next &&
				(!current->bt_node && current->next->bt_node))
			return (0);

		current = current->next;
	}

	free_queue(q);
	free_queue(nodes);

	return (1);
}
