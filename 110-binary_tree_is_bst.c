#include "binary_trees.h"

int valid(const binary_tree_t *node, int left,
		int right);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (valid(tree, INT_MIN, INT_MAX));
}

/**
 * valid - helper function for checking if tree is bst
 * @node: poinet to root node
 * @left: min value
 * @right: max value
 *
 * Return: 1 if tree is bst, otherwise 0
*/
int valid(const binary_tree_t *node, int left,
		int right)
{
	if (node == NULL)
		return (1);
	if (!(node->n < right && node->n > left))
		return (0);

	return (valid(node->left, left, node->n) &&
		valid(node->right, node->n, right));
}
