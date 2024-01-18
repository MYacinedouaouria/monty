#include "monty.h"


/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 *
 * @stack: Points to a pointer to stack_t list
 * @line_number: The number of the current line
 *
 * Return: Void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
		current = current->next;

	current->prev->n = (current->n) % (current->prev->n);
	current->prev->next = NULL;
	free(current);
}
