#include <string.h>
#include "monty.h"

/**
 *
 *
 *
 *
 */
void execute(char *buffer, unsigned int line_number)
{
	char *token = strtok(buffer, " ");
	int round = 1;
	void (*opcode_func)(stack_t **, unsigned int) = NULL;

	while (token != NULL)
	{
		if (round == 1)
		{
			opcode_func = get_opcode_function(token);
			if (opcode_func == NULL)
			{
				printf("L %u: unknown instruction %s\n", line_number, token);
				exit(EXIT_FAILURE);
			}
		}
		if (round == 2)
			head_and_opcode.opcode_arg = token;

		token = strtok(NULL, " ");
		round++;
		if (round > 2)
			break;
	}
	if (opcode_func != NULL)
	{
		opcode_func(&head_and_opcode.head, line_number);
	}
}
