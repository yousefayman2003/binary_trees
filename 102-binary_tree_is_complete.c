#include "binary_trees.h"

size_t binary_tree_size_te(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int head = 0, tail = 0;
	size_t size = 0;
	const binary_tree_t *curr;

	if (tree == NULL)
		return (0);

	/* get size of tree */
	size = binary_tree_size_te(tree);
	/* make a queue */
	const binary_tree_t **queue = malloc(sizeof(const binary_tree_t *) * size);
	/* enqueue the root */
	queue[tail++] = tree;

	while (head < tail)
	{
		/* deque node */
		curr = queue[head++];

		/* if not there is a node*/
		if (curr != NULL)
		{
			queue[tail++] = curr->left;
			queue[tail++] = curr->right;
		}
		else
		{
			while (head < tail)
			{
				if (queue[head++])
					return (0);
			}
		}
	}

	/* free queue */
	free(queue);
	return (1);
}

/**
 * binary_tree_size_te - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree
*/
size_t binary_tree_size_te(const binary_tree_t *tree)
{
	size_t n_nodes = 1;

	if (tree == NULL)
		return (0);

	/* recursively add a node */
	n_nodes += binary_tree_size_te(tree->left);
	n_nodes += binary_tree_size_te(tree->right);

	return (n_nodes);
}
