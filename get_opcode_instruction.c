#include "monty.h"
#include "string.h"
/**
 *
 *
 *
 *
 *
 */
void (*get_opcode_function(char *op))(stack_t **stack, unsigned int line_numbe)
{
	instruction_t instructions[] =
	{
		{"push", push},
		{"pall", pall}
		{NULL, NULL}
	}
	int i = 0;

	while (instructions[i].opcode)
	{
		if (op == instructions[i].opcode)
		{
			return (instructions[i].f);
		}
		i++;
	}
	return (NULL);



}
