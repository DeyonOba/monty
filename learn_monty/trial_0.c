#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *line = NULL;
	size_t n = 0;

	printf("Welcome to Project Monty::::>>\n");
	while (1)
	{
		char **arg;
		char *token;
		char *opcode = NULL;
		char *value = NULL;


		printf("Enter Stack command:\n");
		fflush(stdout);

		if (getline(&line, &n, stdin) == -1)
			break;

		token = strtok(line, " \t\n");
		opcode = strdup(token);
		token = strtok(NULL, " \t\n");
		value = strdup(token);
		printf("opcode: %s\n", opcode);
		printf("value: %s\n", value);
		free(line);
		line = NULL;
		free(opcode);
		free(value);
	}
}

