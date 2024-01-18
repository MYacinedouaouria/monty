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

	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	current->prev->n = (current->prev->n) % (current->n);
	current->prev->next = NULL;
	free(current);
}


/**
 * pstr - Prints the string starting at the top of the stack,
 * followed by a new line
 *
 * @stack: Points to a pointer to stack_t list
 * @line_number: The number of the current line
 *
 * Return: Void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (current == NULL)
		printf("\n");

	while (current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		if (current->n > 127 || current->n <= 0)
			break;

		printf("%c", current->n);

		current = current->prev;
	}
	printf("\n");
}
