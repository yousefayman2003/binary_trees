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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree != NULL && (tree->left == NULL && tree->right == NULL))
		return (1);

	left_h = binary_tree_size_t(tree->left);
	right_h = binary_tree_size_t(tree->right);

	return (left_h - right_h == 0);
}
