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
	char *tokens = strtok(buffer, " ");
	int round = 1;
	void (*opcode_func)(stack_t, unsigned int);

	while (token != NULL)
	{
		if (round == 1)
			opcode_func = get_opcode_function(token);
		if (round == 2)
			opcode_arg = token;

		opcode_func(**head, line_number);

		token = strtok(NULL, delimiters);
		round++;
		break;
	}
}
