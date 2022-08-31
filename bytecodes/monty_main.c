#include "monty.h"


void get_op(char *code, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t valid_opt[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
        {"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
        {"rotl", rotl},
		{"rotr", rotr},
        {"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	for (i = 0; valid_opt[i].opcode; i++)
	{
		if (strcmp(valid_opt[i].opcode, code) == 0)
		{
			valid_opt[i].f(stack, line_number);
			return;
		}
	}

	dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n",
		line_number, code);
	exit(EXIT_FAILURE);
}