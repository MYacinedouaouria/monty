#include "monty.h"
/**
 *
 *
 *
 *
 *
 */
void	pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	if (current->n > 177 && current->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
