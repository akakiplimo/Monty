#include "monty.h"

/* Global flag that holds stack/queue length */
var_t var;

/**
 * free_stack - frees malloced to stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 * Return: nothing
 */
void free_stack(int status, void *arg)
{
stack_t **stack;
stack_t *next;

(void) status;

stack = (stack_t **) arg;

if (*stack)
{
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}
while (*stack != NULL)
{
next = (*stack)->next;
free(*stack);
*stack = next;
}

var.stack_len = 0;
}

/**
 * free_lineptr - frees lineptr returned by getline
 * @status: exit status
 * @arg: pointer to line
 * Return: nothing
 */
void free_lineptr(int status, void *arg)
{
char **lineptr = arg;

(void) status;
if (*lineptr != NULL)
free(*lineptr);
}

/**
 * myfile_close - close file stream
 * @status: exit status
 * @arg: pointer to file stream
 * Return: nothing
 */
void myfile_close(int status, void *arg)
{
  FILE *myfile;
  
  (void) status;
  myfile = (FILE *) arg;
  fclose(myfile);
}

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of arguments passed
 * Return: exitcodes EXIT_FAILURE on failure,
 *         EXIT_SUCCESS on success
 */
int main(int argc, char *argv[])
{
stack_t *stack = NULL;
unsigned int line_number = 0;
FILE *myFile = NULL;
char *lineptr = NULL, *op = NULL;
size_t len = 0;

var.queue = 0;
var.stack_len = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
myFile = fopen(argv[1], "r");
if (myFile == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

on_exit(free_lineptr, &lineptr);
on_exit(free_stack, &stack);
on_exit(myfile_close, myFile);

while (getline(&lineptr, &len, myFile) != -1)
{
line_number++;
op = strtok(lineptr, "\n\t\r ");
if (op != NULL && op[0] != '#')
{
call_op(op, &stack, line_number);
}
}
exit(EXIT_SUCCESS);
}
