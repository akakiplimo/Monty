#include "main.h"

/**
 * call_op - checks ops against opcodes
 * @op: operation to check
 * @stack: double pointer to the beginning of the stack
 * @line_number: file line number
 * Return: void
 */
void call_op(char *op, stack_t **stack, unsigned int line_number)
{
size_t i;
instruction_t operations[] = {
{"push", m_push},
{NULL, NULL}
};

for (i = 0; operations[i].opcode != NULL; i++)
{
if (strcmp(operations[i].opcode, op) == 0)
{
operations[i].f(stack, line_number);
return;
}
}

fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
exit(EXIT_FAILURE);
}
