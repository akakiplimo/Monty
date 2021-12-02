#include "monty.h"

/**
 * op_pall - prints all the numbers in the stack
 * @stack: pointer to the top node of the stack
 * @line_number: the current operation line in the file
 * Return: nothing
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
stack_t *head;
(void)(line_number);

head = *stack;
while (head != NULL)
{
printf("%d\n", head->n);
head = head->next;
if (head == *stack)
return;
}
}
