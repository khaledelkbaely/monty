#include "monty.h"

stack_t *head = NULL;

/**
 * main - main function for monty program
 *
 * @argc: number of arguments passed
 * @argv: argument vector
 *
 * Return: on succes EXIT_SUCCES
 *         on failure EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_open(argv[1]);
	return (0);
}
