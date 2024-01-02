#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure
 * or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);
	/* create a new node */
	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	/* if parent has a left child */
	if (parent->left != NULL)
	{
		parent->left->parent = node;
		node->left = parent->left;
		parent->left = node;
	}
	else
		parent->left = node;

	return (node);
}
