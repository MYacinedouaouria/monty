#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 *
 *
 *
 *
 *
 */
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		FILE *f_ptr = fopen(argv[1], "r");
		char buf[1024];
		int line_number = 1;
		head_and_opcode_arg head_and_opcode = {NULL, NULL};
		if (f_ptr == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while(fgets(buf, 1024, f_ptr))
		{
			execute(buf, line_number);
			
			line_number++;
		}
	}
	return(0);
}
