#include "monty.h"

/**
 * check_isdigit - checks to make sure that a string only contains integers
 * @str: input string
 * Return: 0 if string is digit, 1 if string is not digit
 */
static int check_isdigit(char *str)
{
int i;

for(i=0; str[i]; i++)
{
if (str[i] == '-' && i == 0)
continue;
if (isdigit(str[i]) == 0)
return (1);
}
return (0);
}

/**
 * op_push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: file line number
 * Return: nothing
 */
void op_push(stack_t **stack, unsigned int line_number)
{
stack_t *node;
char *str;
int n;

str = strtok(NULL, "\n\t\r ");
if (str == NULL || check_isdigit(str))
{
fprintf(stderr, "L%u: Usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

n = atoi(str);
node = add_node(stack, n);

if (!node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

var.stack_len++;
}
