#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree node
 * @parent: parent of node to create
 * @value: value to insert in the binary tree
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	return (new);
}
