#include "monty.h"

/**
 * usage_error - prints usage message and exits
 *
 * Return: nothing
 */
void usage_error(void)
{
  fprintf(stderr, "USAGE: monty file\n");
  exit(EXIT_FAILURE);
}

/**
 * file_error - prints file error message and exits
 * @argv: argv given by manin
 *
 * Return: nothing
 */
void file_error(char *argv)
{
  fprintf(stderr, "Error: Can't open file %s\n", argv);
  exit(EXIT_FAILURE);
}

int status = 0;
/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: number of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
  FILE *file;
  size_t buffer_len = 0;
  char *buffer = NULL;
  char *str = NULL;
  stack_t *stack = NULL;
  unsigned int line_num = 1;
  global.data_struct = 1;

  if (argc != 2)
    usage_error();
  
  file = fopen(argv[1], "r");
  
  if(!file)
    file_error(argv[1]);

  while(getline(&buffer, &buffer_len, file) != -1)
    {
      if (status)
	break;
      if(*buffer != '\n')
	{
	  line_num++;
	  continue;
	}

      str = strtok(buffer, "\t\n ");
      if (!str || *str == '#')
	{
	  line_num++;
	  continue;
	}

      global.argument = strtok(NULL, "\t\n ");
      call_op(&stack, str, line_num);
      line_num++;
    }

  free(buffer);
  free_stack(stack);
  fclose(file);
  exit(status);  
}
