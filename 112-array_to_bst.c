#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL, *node, *curr;
	size_t i;

	tree = binary_tree_node(NULL, array[0]);
	for (i = 1; i < size; i++)
	{
		node = binary_tree_node(NULL, array[i]), curr = tree;
		while (1)
		{
			if (array[i] < curr->n)
			{
				if (curr->left != NULL)
					curr = curr->left;
				else
				{
					node->parent = curr;
					curr->left = node;
					break;
				}
			}
			else if (array[i] > curr->n)
			{
				if (curr->right != NULL)
					curr = curr->right;
				else
				{
					node->parent = curr;
					curr->right = node;
					break;
				}
			}
			else
			{
				free(node);
				break;
			}
		}
	}
	return (tree);
}
