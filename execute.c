#include "monty.h"

/**
 * execute_opcode - execute current line opcode
 *
 * @opcode: opcode
 * @value: argument of opcode
 * @line_number: line number
 * Return: Nothing
 */
void execute_opcode(char *opcode, char *value, int line_number)
{
	int i, isopcode = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"div", divide},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	if (*opcode == '#')
		return;
	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			call_func(opcodes[i].f, opcode, value, line_number);
			isopcode = 1;
		}
	}
	if (!isopcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_nodes();
		exit(EXIT_FAILURE);
	}
}

/**
 * call_func - call the opcode function
 *
 * @func: pointer to the function
 * @opcode: opcode string
 * @value: argument passed to opcode
 * @line_number: line number
 *
 * Return: Nothing
 */
void call_func(op_func func, char *opcode, char *value, int line_number)
{
	stack_t *node;
	int sign = 1;
	int i;

	if (strcmp(opcode, "push") == 0)
	{
		if (value && value[0] == '-')
		{
			value++;
			sign = -1;
		}
		if (value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_nodes();
			exit(EXIT_FAILURE);
		}
		for (i = 0; value[i]; i++)
			if (!isdigit(value[i]))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_nodes();
				exit(EXIT_FAILURE);
			}
		node = create_node(atoi(value) * sign);
		func(&node, line_number);
	} else
		func(&head, line_number);
}

/**
 * create_node - creat node on stack
 *
 * @value: value to add
 *
 * Return: pointer to new node
 */
stack_t *create_node(int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = value;
	return (node);
}

/**
 * push - push node to stack
 *
 * @new: new node to add
 * @line_number: line number which have the opcode
 *
 * Return: Nothing
 */
void push(stack_t **new, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (!new || *new == NULL)
	{
		free_nodes();
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tmp = head;
	head = *new;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pall - print all values on the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number which have the opcode
 *
 * Return: Nothing
 */
void pall(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr;

	if (!head || *head == NULL)
		return;
	ptr = *head;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
