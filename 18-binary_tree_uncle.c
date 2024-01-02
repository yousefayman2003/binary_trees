#include "binary_trees.h"

/**
 * binary_tree_uncle -  finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: node's uncle, otherwise NULL if no uncle
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == parent->parent->right)
		return (parent->parent->left);
	else if (parent == parent->parent->left)
		return (parent->parent->right);

	return (NULL);
}
