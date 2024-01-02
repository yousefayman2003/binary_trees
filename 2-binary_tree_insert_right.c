#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure
 * or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	/* create a binary tree node */
	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	/* parent has a right child */
	if (parent->right != NULL)
	{
		parent->right->parent = node;
		node->right = parent->right;
		parent->right = node;
	}
	else
		parent->right = node;

	return (node);
}
