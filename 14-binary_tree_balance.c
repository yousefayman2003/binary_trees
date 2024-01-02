#include "binary_trees.h"

#define max(x, y) (((x) >= (y)) ? (x) : (y))

size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor of tree
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);
	balance_factor = left_h - right_h;

	return (balance_factor);
}
/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of tree
*/
size_t tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* recursivly check for the height */
	return (max(1 + tree_height(tree->left),
			1 + tree_height(tree->right)));
}
