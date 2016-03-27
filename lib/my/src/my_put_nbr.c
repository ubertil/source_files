/*
** my_put_nbr.c for my_put_nbr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:41:42 2015 louis-emile uberti-ares
** Last update Sat Mar 26 23:59:12 2016 louis-emile uberti-ares
*/

#include <unistd.h>

void	my_put_nbr(int nb)
{
  int	modulo;
  int	spliter;

  spliter = 1;
  if (nb < 0)
    {
      write(1, "-", 1);
      nb *= -1;
    }
  while ((nb / spliter) >= 10)
    spliter *= 10;
  while (spliter > 0)
    {
      modulo = ((nb / spliter) %10);
      spliter /= 10;
      my_putchar(modulo + 48);
    }
}

int	my_put_nbr_us(unsigned int nb)
{
  int	spliter;
  int	modulo;
  int	count;

  spliter = 1;
  count = 0;
  while ((nb / spliter) >= 10)
    spliter = spliter * 10;
  while (spliter > 0)
    {
      modulo = ((nb / spliter) %10);
      spliter = spliter / 10;
      count = count + 1;
      my_putchar(modulo + 48);
    }
  return (count);
}
