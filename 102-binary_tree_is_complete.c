#include "binary_trees.h"

size_t tree_size(const binary_tree_t *tree);
int is_complete_tree(binary_tree_t *tree, size_t index, size_t size);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
*/
int binary_tree_is_complete(binary_tree_t *tree)
{
	size_t tree_s;

	if (tree == NULL)
		return (0);
	/* get size of tree */
	tree_s = tree_size(tree);

	/* solve recurisvly */
	return (is_complete_tree(tree, 0, tree_s));
}

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree
*/
size_t tree_size(const binary_tree_t *tree)
{
	size_t n_nodes = 1;

	if (tree == NULL)
		return (0);

	/* recursively add a node */
	n_nodes += tree_size(tree->left);
	n_nodes += tree_size(tree->right);

	return (n_nodes);
}

/**
 * is_complete_tree - sees if a binary tree is complete recurisvuly
 * @tree: pointer to tree node
 * @index: index to check
 * @size: size of binary tree
 * Return: 1 if complete tree, otherwise 0
 */
int is_complete_tree(binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_tree(tree->left, 2 * index + 1, size) &&
		is_complete_tree(tree->right, 2 * index + 2, size));
}
