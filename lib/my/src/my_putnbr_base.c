/*
** my_putnbr_base.c for my_putnbr_base in /home/uberti_l/rendu/Piscine_C_J06/ex_16
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct 13 09:32:00 2015 louis-emile uberti-ares
** Last update Tue Dec 22 11:04:15 2015 louis-emile uberti-ares
*/

#include "include/my.h"

int	my_putnbr_base_pointer(long nbr, char *base)
{
  int	count;

  count = 0;
  if (nbr >= (long)my_strlen(base))
    {
      my_putnbr_base_pointer((nbr / my_strlen(base)), base);
      my_putnbr_base_pointer((nbr % my_strlen(base)), base);
    }
  else
    {
      my_putchar(base[nbr]);
      count = count + 1;
    }
   return (count);
}

int	my_putnbr_base_us(unsigned int nbr, char *base)
{
  int count;

  count = 0;
  if (nbr >= (unsigned int)my_strlen(base))
    {
      my_putnbr_base_us((nbr / my_strlen(base)), base);
      my_putnbr_base_us((nbr % my_strlen(base)), base);
    }
  else
    {
      my_putchar(base[nbr]);
      count = count + 1;
    }
   return (count);
}

int	my_putnbr_base(int nbr, char *base)
{
  int	count;

  count = 0;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
      count = count + 1;
    }
  if (nbr >= my_strlen(base))
    {
      my_putnbr_base((nbr / my_strlen(base)), base);
      my_putnbr_base((nbr % my_strlen(base)), base);
    }
  else
    {
      my_putchar(base[nbr]);
      count = count + 1;
    }
  return (count);
}
