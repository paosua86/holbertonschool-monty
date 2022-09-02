#include "monty.h"

/**
 * _push -  pushes an element to the stack.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 * Return: void.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	size_t i;
	char *arg;

	arg = strtok(NULL, " \n\t\r");
	if (arg == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	for (i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]) && arg[0] != '-')
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	add_node(stack, atoi(arg));
} 

/**
 * _pall - print all values on stack starting from the top
 * @stack: double pointer to head of stack
 * @line_number: line number being executed from script file
 * Return: void
 */

 
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pall;
	(void) line_number;

	pall = *stack;
	while (pall != NULL)
	{
		printf("%d\n", pall->n);
		pall = pall->next;
	}
} 


/**
 * _pint - prints the value at the top of the stack
 * @stack: double pointer to header of the stack.
 * @line_number: counter for line number of the file.
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pint = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", pint->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to header of the stack.
 * @line_number: counter for line number of the file.
 * Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	pop = *stack;
	if ((*stack)->next)
		(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(pop);
}
