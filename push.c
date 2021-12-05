#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_number: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
  char *n = global.argument;
  
  if (isDigit(n) == 0)
    {
      fprintf(stderr, "L%d: usage: push integer", line_number);
      status = EXIT_FAILURE;
      return;
    }
  
  if (global.data_struct == 1)
    {
      if (!add_node(stack, atoi(global.argument)))
	{
	  return;
	  status = EXIT_FAILURE;
	}
    }
  else
    {
      if (!queue_node(stack, atoi(global.argument)))
	{
	  return;
	  status = EXIT_FAILURE;
	}
    }
}
