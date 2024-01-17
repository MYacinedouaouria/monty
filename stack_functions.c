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
 * @line_number: The line which is being parsed
 *
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *current;
	(void) line_number;

	head = *stack;
	current = *stack;

	if (head == NULL)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	while (current != head)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
	printf("%d\n", current->n);

}
