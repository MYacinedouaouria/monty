#include "monty.h"


/**
 * get_opcode_func - Returns a pointer to a function relevant to
 * certain opcode
 * @op: The text to be checked if it have the function asociated to it
 *
 * Return: Void
 */
void (*get_opcode_func(char *op))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	while (instructions[i].opcode)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}
	return (NULL);
}
