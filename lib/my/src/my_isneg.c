/*
** my_isneg.c for my_isneg in /home/uberti_l/day03
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Sep 30 10:44:58 2015 louis-emile uberti-ares
** Last update Sat Dec 12 08:20:31 2015 louis-emile uberti-ares
*/

#include "include/my.h"

int	my_isneg(int nb)
{
  if (nb < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
