#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	size_t i;
	size_t len = 0;
	char *arg;

	arg = strtok(NULL, " \t\r\n\v\f");
	if (arg == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		/* free? */
		exit(EXIT_FAILURE);
	}
	len = strlen(arg);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(arg[i]) && arg[0] != '-')
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			/* free? */
			exit(EXIT_FAILURE);
		}
		add_node(stack, atoi(arg));
	}
}


void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pall;
	(void) line_number;

	pall = *stack;
	while (pall != NULL)
	{
		printf("%d\n", pall->n);
		pall = pall->next;
		if (pall == NULL)
		{
			return;
		}
	}
}

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pint = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		/*free?*/
		exit(EXIT_FAILURE);
	}
	printf("%d\n", pint->n);
}