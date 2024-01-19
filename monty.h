#ifndef _MONTY_H_
#define _MONTY_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global - list head and opcode argument
 * @opcode_arg: Stores the opcode argument
 * @head: The list's head
 * @f_ptr: the file passed as an argument
 * Description: To be used when making the members globally
 * available in all files
 */
typedef struct global
{
	char *opcode_arg;
	stack_t *head;
} head_and_opcode_arg;
extern head_and_opcode_arg head_and_opcode;


/* tools.c */
int isValidInteger(char *string);
void free_list(void);

/* stack_functions.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* stack_functions2.c */
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);

/* parser.c */
void execute(char *buffer, unsigned int line_number);

/* stack_functions3.c */
void mod(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* stack_functions4.c */
void pchar(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

/* get_opcode_instruction.c */
void (*get_opcode_func(char *op))(stack_t **stack, unsigned int line_number);


#endif /* _MONTY_H_ */
