#include "binary_trees.h"

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
	binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		temp = (binary_tree_t *) second;

		while (temp)
		{
			if (temp == first)
				return ((binary_tree_t *) first);

			temp = temp->parent;
		}

		first = first->parent;
	}

	return (NULL);
}
