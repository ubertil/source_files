/*
** my_mult.c for my_mult in /home/uberti_l/rendu/Piscine_C_evalexpr/multiplication
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 26 10:15:31 2015 louis-emile uberti-ares
** Last update Mon Oct 26 11:10:42 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "../include/my.h"

int	my_display(int idx, char *dest, int *tab)
{
  int	i;

  i = idx + 1;
  if (tab[5] != 0)
    my_put_nbr(tab[5]);
  while (i >= 0)
    {
      my_putchar(dest[i]);
      i = i - 1;
    }
}

int	my_mult(int *tab, char *dest, char **argv)
{
  int	idx;

  idx = 1;
  tab[5] = 0;
  while ((tab[0] > 0) || (tab[1] > 0))
    {
      tab[2] = (tab[0] > 0) ? (argv[1][my_strlen(argv[1]) - idx] - 48) : (0);
      tab[3] = (tab[1] > 0) ? (argv[2][my_strlen(argv[2]) - idx] - 48) : (0);
      if ((tab[2] + tab[5]) * tab[3] <= 9)
	{
      dest[idx - 1] = tab[4] + 48;
      tab[0] = tab[0] - 1;
      tab[1] = tab[1] - 1;
      idx = idx + 1;
      my_
    }
}

int	main(int argc, char **argv)
{
  int	tab[7];
  char	*dest;

  tab[0] = my_strlen(argv[1]);
  tab[1] = my_strlen(argv[2]);
  if ((argv[1][0] == '-') ^ (argv[2][0] == '-'))
    my_putchar('-');
  if ((argv[1][0] == '0') ^ (argv[2][0] == '0'))
    {
      dest = malloc(1);
      dest[0] = 48;
      dest[1] = '\0';
      my_putstr(dest);
      return (0);
    }
  dest = malloc(tab[0] + tab[1]);
  my_mult(tab, dest, argv);
}
