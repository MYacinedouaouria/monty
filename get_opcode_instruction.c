#include "monty.h"
/**
 *
 *
 *
 *
 *
 */
void (*get_opcode_function(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] =
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

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
