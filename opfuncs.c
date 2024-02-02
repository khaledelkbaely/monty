#include "monty.h"

/**
 * pint - print the value at the top of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!head || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - remove the top element of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	if (!head || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	ptr = ptr->next;
	if (ptr != NULL)
		ptr->prev = NULL;
	free(*head);
	*head = ptr;
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int line_number)
{
	int tmp;

	if (!head || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next->n;
	(*head)->next->n = (*head)->n;
	(*head)->n = tmp;
}

/**
 * add - adds the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void add(stack_t **head, unsigned int line_number)
{
	if (!head || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	pop(head, line_number);
}

/**
 * nop - does not do anything
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

