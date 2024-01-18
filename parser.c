#include <string.h>
#include "monty.h"

/**
 * execute - Takes in the buffer of file's line content and
 * maps it to it related function
 * @buffer: The file's line content
 * @line_number: The file's line number to be parsed
 *
 * Return: Void
 */
void execute(char *buffer, unsigned int line_number)
{
	char *token = strtok(buffer, " \n");
	int round = 1;
	void (*opcode_func)(stack_t **, unsigned int) = NULL;

	if (strncmp((buffer, "#", 1) == 0) || (strcmp(token, "") == 0))
		return;
	while (token != NULL)
	{
		if (strcmp(token, "") == 0)
			continue;
		if (round == 1)
		{
			opcode_func = get_opcode_func(token);
			if (opcode_func == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
				exit(EXIT_FAILURE);
			}
		}
		if (round == 2)
			head_and_opcode.opcode_arg = token;

		token = strtok(NULL, " \n");
		round++;
		if (round > 2)
			break;
	}
	if (opcode_func != NULL)
	{
		opcode_func(&head_and_opcode.head, line_number);
	}
}
