#include "binary_trees.h"

#define max(x, y) (((x) >= (y)) ? (x) : (y))

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL || ((tree->right == NULL) &&
			(tree->left) == NULL))
		return (0);

	/* recursivly check for the height */
	return (max(1 + binary_tree_height(tree->left),
			1 + binary_tree_height(tree->right)));
}
