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
 * fill_parents - Fill a queue with the node's parents
 * @node: Pointer to the node of the binary tree
 *
 * Return: Pointer to the queue
 */
queue *fill_parents(binary_tree_t *node)
{
	queue *parents;
	qnode *new;
	binary_tree_t *current;

	if (!node)
		return (NULL);

	parents = init_queue();
	if (!parents)
		return (NULL);

	current = node;

	new = enqueue(parents, current);
	if (!new)
	{
		free_queue(parents);
		return (NULL);
	}


	while (current->parent)
	{
		current = current->parent;
		new = enqueue(parents, current);
		if (!new)
		{
			free_queue(parents);
			return (NULL);
		}
	}

	return (parents);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node.
 * @second: Pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor of the two nodes, if any.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	queue *f_parents, *s_parents;
	qnode *fp, *sp;

	if (!first || !second)
		return (NULL);

	f_parents = fill_parents((binary_tree_t *) first);
	s_parents = fill_parents((binary_tree_t *) second);

	if (!f_parents || !s_parents)
	{
		free_queue(f_parents);
		free_queue(s_parents);
		return (NULL);
	}

	for (fp = f_parents->front; fp; fp = fp->next)
	{
		for (sp = s_parents->front; sp; sp = sp->next)
		{
			if (fp->bt_node == sp->bt_node)
			{
				free_queue(f_parents);
				free_queue(s_parents);
				return (fp->bt_node);
			}
		}
	}


	free_queue(f_parents);
	free_queue(s_parents);
	return (NULL);
}
