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
	stack_t *curr = globals.head, *helper;

	while (curr != NULL)
	{
		helper = curr;
		curr = curr->next;
		free(helper);
	}

	globals.head = NULL;
}


/**
 * add_at_bottom - add the given node at the bottom of a doubly list
 * @new: The pointer to the newly created node
 *
 * Return: Void
 */
void add_at_bottom(stack_t *new)
{
	stack_t *current = globals.head;

	new->prev = NULL;
	new->next = current;
	current->prev = new;
	globals.head = new;
	globals.opcode_arg = NULL;
}
