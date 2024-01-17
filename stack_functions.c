#include "monty.h"
/**
 *
 *
 *
 */
void	push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;

	if (head_and_opcode.opcode_arg == NULL)
	{
		printf("L %u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(head_and_opcode.opcode_arg);
	new->next = NULL;
	current = *stack;
	if(*stack == NULL)
	{
		new->prev = *stack;
		*stack = new;
	}
	if (current != NULL)
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		new->prev = current;
		current->next = new;
	}
	head_and_opcode.opcode_arg = NULL;	
}
/**
 *
 *
 *
 */
void	pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *current;
	 (void) line_number;

	head = *stack;
	current = *stack;
	
	if (head == NULL)
	{
		return ;
	}
	while(current->next != NULL)
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
