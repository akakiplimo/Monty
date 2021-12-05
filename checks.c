#include "monty.h"

/**
 * isDigit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int isDigit(char *str)
{
  if (!str || *str == '\0')
    return (0);
  if (*str == '-')
    str++;
  while (*str)
    {
      if (isdigit(*str) == 0)
	return (0);
      str++;
    }
  return (1);
}

/**
 * isNumber - checks if a string is a number
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int isNumber(char *str)
{
  int i;

  if (!str)
    return (0);

  for (i = 0; str[i]; i++)
    {
      if (i < '0' || i > '9')
	return (0);
    }
  return (1);
  
}
