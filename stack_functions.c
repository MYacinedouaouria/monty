#include "monty.h"


/**
 * push - push to the stack
 * @stack: The address of the stack's head
 * @line_number: The line which is being parsed
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;
	char *arg = head_and_opcode.opcode_arg;

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list();
		exit(EXIT_FAILURE);
	}
	if (atoi(arg) == 0 && *arg != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	new->n = atoi(arg);
	new->next = NULL;
	current = *stack;
	if (*stack == NULL)
	{
		new->prev = *stack;
		*stack = new;
	}
	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		new->prev = current;
		current->next = new;
	}
	head_and_opcode.opcode_arg = NULL;
}


/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: The address of the stack's head
 * @line_number: The line which is being parsed(not used)
 *
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	current = *stack;

	if (current == NULL)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
/**
 *print -  prints the value at the top of the stack
 *@stack: points to a pointer to stack_t list
 *@line_number: the number of the current line
 *
 *
 */
void	pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	printf("%d\n", current->n);
}
