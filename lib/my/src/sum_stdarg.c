/*
** sum_stdarg.c for sum_stdarg in /home/uberti_l/rendu/PSU_2015_my_printf_bootstrap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Nov  4 11:31:38 2015 louis-emile uberti-ares
** Last update Wed Nov  4 11:33:12 2015 louis-emile uberti-ares
*/

#include "include/my.h"
#include <stdarg.h>

int		sum_stdarg(int i, int nb, ...)
{
  va_list	list;
  int		temp;

  temp = 0;
  va_start(list, nb);
  if (i == 0)
    while (i <= nb)
      {
	temp = temp + va_arg(list, int);
	i = i + 1;
      }
  if (i == 1)
    while (i <= nb)
      {
	temp = temp + my_strlen(va_arg(list, char *));
	i = i + 1;
      }
  else
    return (1);
  my_put_nbr(temp);
  va_end(list);
  return (0);
}
