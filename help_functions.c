#include "monty.h"

/**
 * add_node - adds the top two elements of the stack
 * @stack: double pointer to header of the stack
 * @argument: counter
 *
 * Return: void.
 */

stack_t *add_node(stack_t **stack, int argument)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	return (new_node);
}
