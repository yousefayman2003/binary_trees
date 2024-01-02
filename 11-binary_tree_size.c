#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n_nodes = 1;

	if (tree == NULL)
		return (0);

	/* recursively add a node */
	n_nodes += binary_tree_size(tree->left);
	n_nodes += binary_tree_size(tree->right);

	return (n_nodes);
}
