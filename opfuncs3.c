#include "monty.h"
#include <ctype.h>

/**
 * pchar - prnt the char at the top of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: the line number of the opcode
 *
 * Return: Nothing
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (!head || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	if (!isascii((*head)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
/**
 * pstr - print the string at the top of the stack
 *
 * @head: pointer to the head of the stack
 * @line_number: the line number of the opcode
 *
 * Return: Nothing
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	if (!head || *head == NULL)
	{
		putchar('\n');
		return;
	}
	ptr = *head;
	while (ptr && ptr->n != 0 && !isascii(ptr->n))
	{
		printf("%c\n", ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 *
 * @head: pointer to the head of the stack
 * @line_number: the line number of the opcode
 *
 * Return: Nothing
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	if (!head || *head == NULL || (*head)->next == NULL)
		return;

	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = *head;
	(*head)->prev = ptr;
	*head = (*head)->next;
	(*head)->prev = NULL;
	ptr->next->next = NULL;
}
/**
 * rotr - rotates the stack to the bottom
 *
 * @head: pointer to the head of the stack
 * @line_number: the line number of the opcode
 *
 * Return: Nothing
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (!head || *head == NULL || (*head)->next == NULL)
		return;

	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->prev->next = NULL;
	ptr->prev = NULL;
	ptr->next = *head;
	(*head)->prev = ptr;
	*head = ptr;
}
