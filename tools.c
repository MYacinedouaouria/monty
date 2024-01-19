#include "monty.h"


/**
 * isValidInteger - Checks if the string contain an integer
 * @string: String to be parsed
 *
 * Return: 1 if the string is int else 0
 */
int isValidInteger(char *string)
{
	char *endptr;

	strtol(string, &endptr, 10);

	if (*endptr != '\0' || string == endptr)
		return (0);

	return (1);
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
