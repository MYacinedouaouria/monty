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
	char *arg = globals.opcode_arg;
	stack_t *current, *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list();
		exit(EXIT_FAILURE);
	}
	if (arg == NULL || !isValidInteger(arg))
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
		new->prev = NULL;
		globals.head = new;
		return;
	}
	if (globals.isStackOn == 0 && *stack != NULL)
	{
		add_at_bottom(new);
		return;
	}
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
	globals.opcode_arg = NULL;
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
		current = current->next;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
/**
 * pint -  prints the value at the top of the stack
 * @stack: points to a pointer to stack_t list
 * @line_number: the number of the current line
 *
 * Return: Void
 */
void pint(stack_t **stack, unsigned int line_number)
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


/**
 * pop - Removes the top element of the stack
 * @stack: Points to a pointer to stack_t list
 * @line_number: The number of the current line
 *
 * Return: Void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *previous;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next == NULL)
	{
		free(current);
		globals.head = NULL;
		return;
	}
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	free(current);
}


/**
 * swap -  swaps the top two elements of the stack
 * @stack: Points to a pointer to stack_t list
 * @line_number: The number of the current line
 *
 * Return: Void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int previous_n;
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
	{
		current = current->next;
		previous_n = current->n;
	}
	current->n = current->prev->n;
	current->prev->n = previous_n;
}
