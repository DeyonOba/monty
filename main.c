#include "monty.h"

instruction_t opcode_f[] = {
	{"pall", pall},
	{"push", push},
	{NULL, NULL},
};

/**
 */
int main(int argc, char **argv)
{
	stack_t *stack_queue = NULL;
	unsigned int line_number = 1;
	char *line = NULL, *token;
	size_t size = 0;
	int i;
	FILE *file = NULL;

	/* if user gives no argument or more than one argument*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	/* if the file failed to open argv[1] return the error*/
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &size, file) != -1)
	{
		token = strtok(line, " \t\n");
		if (token != NULL)
		{
			for (i = 0; opcode_f[i].opcode != NULL; i++)
			{
				if (strcmp(opcode_f[i].opcode, token) == 0)
				{
					opcode_f[i].f(&stack_queue, line_number);
					break;
				}
			}
			if (opcode_f[i].opcode == NULL)
			{
				fprintf(
						stderr, "L%u: unknown instruction %s\n",
						line_number, token);
				exit(EXIT_FAILURE);
			}
		}
		free(line);
	       line_number++, line = NULL;	
	}

	return (EXIT_SUCCESS);
}

