#include "monty.h"

/**
 * call_op - function in charge of calling opcodes
 * @stack: stack given by main
 * @str: string to compare
 * @line_number: number of lines
 *
 * Return: nothing
 */
void call_op(stack_t **stack, char *str, unsigned int line_number)
{
  int i = 0;
  instruction_t op[] = {
    { "push", push },
    { "pall", pall },
    { NULL, NULL }
  };

  if (!strcmp(str, "stack"))
    {
      global.data_struct = 1;
      return;
    }
  if (!strcmp(str, "queue"))
    {
      global.data_struct = 0;
      return;
    }

  while (op[i].opcode)
    {
      if (strcmp(op[i].opcode, str) == 0)
	{
	  /* if match found, run the function */
	  op[i].f(stack, line_number);
	  return;
	}
      i++;
    }

  fprintf(stderr, "L%d:: unknown instruction %s\n", line_number, str);
  status = EXIT_FAILURE;
}
