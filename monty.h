#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#define _DEFAULT_SOURCE

#define STACK 0
#define QUEUE 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * var_s - struct for the main variables of the Monty Interpreter
 * @queue: flag to determine if in stack or queue mode
 * @stack_len: length of the stack
 */
typedef struct var_s
{
  int queue;
  size_t stack_len;
} var_t;

/* variable structure to hold flag for queue or stack length */
extern var_t var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(int status, void *arg);
void free_lineptr(int status, void *arg);
void myfile_close(int status, void *arg);
void call_op(char *op, stack_t **stack, unsigned int line_number);

stack_t *add_node(stack_t **stack, const int n);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
