#include "monty.h"

/**
 * sub - subtracts the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void sub(stack_t **head, unsigned int line_number)
{
	if (!head || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, line_number);
}

/**
 * divide - divides the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void divide(stack_t **head, unsigned int line_number)
{
	if (!head || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	pop(head, line_number);
}

/**
 * mul - multiplies the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (!head || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	pop(head, line_number);
}
/**
 * mod - computes the remainder the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: line number of the current opcode
 * Return: Nothing
 */
void mod(stack_t **head, unsigned int line_number)
{
	if (!head || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n %= (*head)->n;
	pop(head, line_number);
}
