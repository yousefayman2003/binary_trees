#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing
 *		the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
			return (root->right);
		else if (!root->right)
			return (root->left);

		/* finding min value from right sub-tree */
		bst_t *curr = root->right;

		while (curr->left)
			curr = curr->left;
		root->n = curr->n;
		root->right = bst_remove(root->right, root->n);
	}

	return (root);
}
