#include "monty.h"

char **opcode = NULL;

int main(int arg, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	FILE *_file = NULL;
	char *lineptr = NULL, *code = NULL;
	size_t len = 0;

	if (arg != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_file = fopen(argv[1], "r");
	if (_file == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&lineptr, &len, _file) != EOF)
	{
		code = strtok(lineptr, " \n\v\f\t\r");
		if (code != NULL && code[0] != '#')
			get_op(&stack, line_number, code);
		line_number++;
	}
	/*add free*/
	exit(EXIT_SUCCESS);
	
}


/* void free(stack_t *head)
{
	stack_t *tmp;
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (0);
}*/



void get_op(stack_t **stack, unsigned int line_number, char *code)
{
	int i;
	instruction_t valid_opt[] = {
		{"push", _push},
		{"pall", _pall},
		/*{"pint", _pint},
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
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue}, */
		{NULL, NULL}
	};

	for (i = 0; valid_opt[i].opcode != NULL; i++)
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
