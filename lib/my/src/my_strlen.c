/*
** my_strlen.c for my_strlen in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:57:52 2015 louis-emile uberti-ares
** Last update Thu May  5 14:51:21 2016 louis-emile uberti-ares
*/

#include <stdlib.h>

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    ++i;
  return (i);
}
