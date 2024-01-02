#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: count
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);

	/* node has atleast 1 child */
	if (tree->left != NULL || tree->right != NULL)
		counter = 1;

	counter += binary_tree_nodes(tree->left);
	counter += binary_tree_nodes(tree->right);

	return (counter);
}
