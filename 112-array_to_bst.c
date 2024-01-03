#include "binary_trees.h"

void insert_node(bst_t **curr, bst_t **node, int value);

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree, *node, *curr;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	tree = binary_tree_node(NULL, array[0]);
	if (tree == NULL)
		return (NULL);

	for (i = 1; i < size; i++)
	{
		node = binary_tree_node(NULL, array[i]), curr = tree;
		if (node == NULL)
			return (NULL);

		insert_node(&curr, &node, array[i]);
	}
	return (tree);
}

/**
 * insert_node - inserts node in a bst
 * @curr: double pointer to root node
 * @node: double pointer to new node to insert
 * @value: value of new node
*/
void insert_node(bst_t **curr, bst_t **node, int value)
{
	while (1)
	{
		if (value < (*curr)->n)
		{
			if ((*curr)->left != NULL)
				*curr = (*curr)->left;
			else
			{
				(*node)->parent = *curr;
				(*curr)->left = *node;
				return;
			}
		}
		else if (value > (*curr)->n)
		{
			if ((*curr)->right != NULL)
				*curr = (*curr)->right;
			else
			{
				(*node)->parent = *curr;
				(*curr)->right = *node;
				return;
			}
		}
		else
		{
			free(*node);
			return;
		}
	}
}
