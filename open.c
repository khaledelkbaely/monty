#include "monty.h"

/**
 * file_open - open file and check for error
 *
 * @file_name: name of file to open
 *
 * Return: Nothing
 */
void file_open(char *file_name)
{
	FILE *fptr;

	if (file_name != NULL)
		fptr = fopen(file_name, "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	parse_file(fptr);
	fclose(fptr);
}

/**
 * parse_file - read file line by line
 *
 * @fptr: pointer to file
 * Return: Nothing
 */
void parse_file(FILE *fptr)
{
	int line_number = 1;
	char *buf = NULL;
	size_t size = 0;

	for (line_number = 1; getline(&buf, &size, fptr) != -1; line_number++)
	{
		parse_line(buf, line_number);
	}

	free(buf);
}

/**
 * parse_line - execute lines
 *
 * @line: line to execute
 * @line_number: number of line
 * Return: Nothing
 */
void parse_line(char *line, int line_number)
{
	char *opcode, *val;
	const char *delim = "\n ";

	opcode = strtok(line, delim);
	if (opcode == NULL || *opcode == '#')
		return;
	val = strtok(NULL, delim);
	execute_opcode(opcode, val, line_number);
}
