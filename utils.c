#include "monty.h"

/**
 * add_node - adds a node to the beginning of the stack
 * @stack: pointer to the stack HEAD
 * @n: number to be added to the new node
 *
 * Return: new node, if creation fails return NULL
 */
stack_t *add_node(stack_t **stack, const int n)
{
  stack_t *node = malloc(sizeof(stack_t));

  if (!node)
    {
      fprintf(stderr, "Error: malloc failed\n");
      free(node);
      return (NULL);
    }

  node->n = n;
  node->next = *stack;
  node->prev = NULL;
  if (*stack)
    (*stack)->prev = node;

  *stack = node;
  return (node);
}

/**
 * queue_node - adds a node to a stack_t stack in queue node
 * @stack: pointer to the stack head
 * @n: number to be added to the node
 *
 * Return: new node, if memory allocation fails, return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
  stack_t *node = malloc(sizeof(stack_t));
  stack_t *current = *stack;

  if (!node)
    {
      free(node);
      return (NULL);
    }
  node->n = n;

  if (!*stack)
    {
      node->next = NULL;
      node->prev = NULL;
      *stack = node;
      return (node);
    }

  while (current)
    {
      if(!current->next)
	{
	  node->next = NULL;
	  node->prev = current;
	  current->next = node;
	  break;
	}
      current = current->next;
    }

  return (node);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: pointer to the stack HEAD
 *
 * Return: number of elements of the stack
 */
size_t print_stack(const stack_t *stack)
{
  size_t size = 0;
  
  while (stack)
    {
      printf("%d\n", stack->n);
      stack = stack->next;
      size++;
    }

  return (size);
}

/**
 * free_stack - frees a populated stack
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
  stack_t *current = stack;
  stack_t *next;

  if (stack)
    {
      next = stack->next;
      while (current)
	{
	  free(current);
	  current = next;
	  if (next)
	    next = next->next;
	}
    }
}
