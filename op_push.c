#include "main.h"

/**
 * check_isdigit - checks to make sure that a string only contains integers
 * @arg: input string
 * Return: 0 if string is digit, 1 if string is not digit
 */
static int check_isdigit(char *str)
{
int i;

for(i=0; arg[i]; i++)
{
if (arg[i] == '-' && i == 0)
continue;
if (isdigit(argi[i]) == 0)
return (1);
}
return (0);

}

/**
 * op_push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: file line number
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
char *arg;
int n;

arg = strtok(NULL, "\n\t\r");
if (arg == NULL || check_isdigit(arg))
{
fprintf(stderr, "L%u: Usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

n = atoi(arg);
if(!add_node(stack, n))
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

var.stack_len++;
}
