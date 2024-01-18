#include "monty.h"
/**
 *add - adds the top two elements of the stack
 *@stack: points to a pointer to stack_t list
 *@line_number: the current line number
 *Return: void
 *
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->prev->n += current->n;
	pop(stack, line_number);
}
/**
 *nop - doesn’t do anything.
 *@stack: points to a pointer to stack_t list
 *@line_number: the current line number
 *
 *
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
