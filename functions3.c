#include "monty.h"

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: double pointer to header of the stack
 * @line_number: counter for line number of the file
 * Return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *mod = *stack;
	size_t len = stack_length(*stack);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = mod->next;
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod->n %= (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: double pointer to header of the stack.
 * @line_number: counter for line number of the file.
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
    printf("%c\n", (*stack)->n);
}
