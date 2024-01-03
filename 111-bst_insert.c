#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *curr, *prev;

	if (*tree == NULL)
	{
		node = binary_tree_node(NULL, value);
		*tree = node;
		return (node);
	}

	curr = *tree;
	while (curr)
	{
		prev = curr;
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
		else
			return (NULL);
	}
	/* create node */
	node = binary_tree_node(NULL, value);

	if (node == NULL)
		return (NULL);

	node->parent = prev;

	if (value < prev->n)
		node->parent->left = node;
	else
		node->parent->right = node;

	return (node);
}
