#include "binary_trees.h"

void enqueue_node(queue **head, binary_tree_t *node);
void dequeue_node(queue **head);

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 *
 * @tree: the root node of the binary tree
 * @func: a function that prints the data value of a binary tree node
 */
void binary_tree_levelorder(binary_tree_t *tree, void (*func)(int))
{
	queue *head = NULL;

	if (tree == NULL || func == NULL)
		return;

	if (!(tree->right || tree->left))
	{
		func(tree->n);
		return;
	}
	
	/* append root node */
	enqueue_node(&head, tree);
	while (head)
	{
		/* print node */
		func(tree->n);
		
		/* add children to queue */
		if (tree->left)
			enqueue_node(&head, tree->left);
		if (tree->right)
			enqueue_node(&head, tree->right);

		/* deque node */
		dequeue_node(&head);

		if (head)
			tree = head->node;
	}
}

/**
 * enqueue_node - enqueues a node to a queue
 * @head: double pointer to head of queue
 * @node: node to append
 */
void enqueue_node(queue **head, binary_tree_t *node)
{
	queue *new_node, *temp;

	new_node = malloc(sizeof(queue));
	if (new_node == NULL)
		return;
	new_node->node = node;
	new_node->next = NULL;

	if ((*head) == NULL)
	{
		*head = new_node;
		return;
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;

	/* append new node to queue */
	temp->next = new_node;
}

/**
 * dequeue_node - deques a node from queue
 * @head: double pointer of queue head
 */
void dequeue_node(queue **head)
{
	queue *temp;

	if (!*head)
		return;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
