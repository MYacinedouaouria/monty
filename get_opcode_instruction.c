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
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mod", mod},
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
/**
 * free_list - free the list
 *
 * Return: Void
 */
void free_list(void)
{
	stack_t *curr = head_and_opcode.head, *helper;

	while (curr != NULL)
	{
		helper = curr;
		curr = curr->next;
		free(helper);
	}

	head_and_opcode.head = NULL;
}
