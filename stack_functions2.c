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
/**
 *sub - subtracts the top element from the second top element of the stack
 *@stack: points to a pointer to a stack_t list
 *@line_number: the number of the current line
 *
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->prev->n -= current->n;
	pop(stack, line_number);
}
/**
 *div2 - divides the second top element of the stack by the top element
 *@stack: points to a pointer to a stack_t list
 *@line_number: the number of the current line
 *
 *
 */
void div2(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	current->prev->n = current->prev->n / current->n;
	pop(stack, line_number);
}
