#include "monty.h"
/**
 *pchar - prints the string starting at the top of the stack
 *@stack: points to a pointer to stack_t list
 *@line_number: the number of the current line
 *
 *
 */
void	pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
