#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return:  pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	/* make the new root the right child */
	new_root = tree->right;
	/* change the parent */
	new_root->parent = tree->parent;
	tree->parent = new_root;

	/* make the right of prev node to be the root left child */
	tree->right = new_root->left;

	/* if there is right child change parent */
	if (tree->right)
	{
		tree->right->parent = tree;
	}

	/* change new root left child */
	new_root->left = tree;

	return (new_root);
}
