#include "monty.h"
#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv);

instruction_t opcode_f[] = {
	{"pall", pall},
	{"push", push},
	{"pint", pint},
	{"pop", pop},
	{"add", add},
	{"swap", swap},
	{"nop", nop},
	{"sub", sub},
	{"div", divide},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	/**{"rotr", rotr},**/
	{NULL, NULL},
};

stack_t *stack_queue = NULL;
char *line = NULL;
FILE *file = NULL;

/**
 * main - Program entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Integer 0 (Success), or 1 (Failure)
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 1;
	size_t max_line_length = MAX_LINE_LENGTH;
	char *token;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_resources();
		exit(EXIT_FAILURE);
	}

	line = malloc(max_line_length);
	if (line == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_resources();
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		token = strtok(line, " \t\n");
		if (token != NULL)
		{
			if (token[0] == '#')
				continue;

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
				free_resources();
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	free_resources();
	return (EXIT_SUCCESS);
}

/**
 * free_resources - Free dynamicall allocation resources used by monty
 */
void free_resources(void)
{
	if (file != NULL)
	{
		fclose(file);
	}
	if (stack_queue != NULL)
	{
		free_list(stack_queue);
	}
	if (line != NULL)
	{
		free(line);
	}
}
