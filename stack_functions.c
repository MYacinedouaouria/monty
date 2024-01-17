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
	if (*current != NULL)
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		new->prev = current;
		current-next = new;
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
}
