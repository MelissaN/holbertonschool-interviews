#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node as the right child
 * @parent: parent of node to insert
 * @value: value to insert on right of parent
 * This function builds on the one to create a node (file 0-...)
 * If a node is already there, move it down as right child
 * Return: pointer to the newly inserted node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (parent->right)
	{
		new->right = parent->right;
		(new->right)->parent = new;
	}
	parent->right = new;

	return (new);
}
