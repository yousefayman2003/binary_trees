#include "binary_trees.h"

/**
 * binary_tree_size_t - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree
*/
size_t binary_tree_size_t(const binary_tree_t *tree)
{
	size_t n_nodes = 1;

	if (tree == NULL)
		return (0);

	/* recursively add a node */
	n_nodes += binary_tree_size_t(tree->left);
	n_nodes += binary_tree_size_t(tree->right);

	return (n_nodes);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int head = 0, tail = 0;
	size_t size = 0;
	const binary_tree_t *curr;

	if (tree == NULL)
		return;

	/* get size of tree */
	size = binary_tree_size_t(tree);
	/* make a queue */
	const binary_tree_t **queue = malloc(sizeof(const binary_tree_t *) * size);
	/* enqueue the root */
	queue[tail++] = tree;

	while (head < tail)
	{
		/* deque node */
		curr = queue[head++];

		/* print node value */
		func(curr->n);

		/* enqueue children */
		if (curr->left)
			queue[tail++] = curr->left;

		if (curr->right)
			queue[tail++] = curr->right;
	}
}
