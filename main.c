#include "monty.h"
#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv);

instruction_t opcode_f[] = {
	{"pall", pall},
	{"push", push},
	{NULL, NULL},
};

/**
 * main - Program entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Integer 0 (Success), or 1 (Failure)
 */
int main(int argc, char **argv)
{
	stack_t *stack_queue = NULL;
	unsigned int line_number = 1;
	char *line = NULL, *token;
	int i;
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
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
				fprintf(stderr, "L%u: unknown instruction %s\n",
						line_number, token);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
