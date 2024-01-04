#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	
	/* change new root */
	new_root = tree->left;
	
	/* change parents */
	new_root->parent = tree->parent;
	tree->parent = new_root;

	/* assign right child of new root to prev root */
	tree->left = new_root->right;
	if (tree->left != NULL)
	{
		tree->left->parent = tree;
	}
	/* assign new right of new root */
	new_root->right = tree;

	return (new_root);
}
