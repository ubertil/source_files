/*
** format2.c for my_format2 in /home/uberti_l/rendu/PSU_2015_my_printf
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov  9 17:15:42 2015 louis-emile uberti-ares
** Last update Tue Dec 22 11:19:21 2015 louis-emile uberti-ares
*/

#include <stdarg.h>
#include "include/my.h"
int	my_putnbr_base(unsigned int nbr, char *base, int count);
int	my_putnbr_base_p(long nbr, char *base, int count);

int	my_format_b(va_list list)
{
  int	count;

  count = 0;
  count = my_putnbr_base(va_arg(list, unsigned int), "01", count);
  return (count);
}

int	my_format_c(va_list list)
{
  my_putchar(va_arg(list, int));
  return (1);
}

int	my_format_s(va_list list)
{
  int	count;

  count = my_putstr(va_arg(list, char *));
  return (count);
}

int	my_format_p(va_list list)
{
  int	count;

  count = 3;
  my_putstr("0x");
  count = my_putnbr_base_p(va_arg(list, long), "0123456789abcdef", count);
  return (count);
}

int	my_format_S(va_list list)
{
  int	count;

  count = my_showstr(va_arg(list, char *));
  return (count);
}
