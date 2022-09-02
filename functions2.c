#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: double pointer to header of the stack
 * @line_number: counter for line number of the file
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *sum = *stack;
	size_t len = stack_length(*stack);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = sum->next;
	sum->n += (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _nop - doesn’t do anything
 * @stack: double pointer to header of the stack
 * @line_number: counter for line number of the file
 * Return: void
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * _sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: double pointer to header of the stack
 * @line_number: counter for line number of the file
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *sub = *stack;
	size_t len = stack_length(*stack);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = sub->next;
	sub->n -= (*stack)->n;
	_pop(stack, line_number);
}