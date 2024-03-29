#include "monty.h"

head_and_opcode_arg globals = {NULL, NULL, 1};


/**
 * main - The program's main entrance
 * @argc: The count of cmd_line args
 * @argv: The list of all cmd_line args
 *
 * Return: Int
 */
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		FILE *f_ptr = fopen(argv[1], "r");
		char buf[1024];
		int line_number = 1;

		if (f_ptr == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while (fgets(buf, 1024, f_ptr))
		{
			execute(buf, line_number);

			line_number++;
		}
		fclose(f_ptr);
		free_list();
	}
	return (0);
}
