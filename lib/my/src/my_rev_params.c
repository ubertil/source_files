/*
** my_rev_params.c for my_rev_params in /home/uberti_l/rendu/Piscine_C_J07/ex_05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 13:21:16 2015 louis-emile uberti-ares
** Last update Tue Dec 22 11:21:22 2015 louis-emile uberti-ares
*/

#include "include/my.h"

int	my_rev_params(int argc, char **argv)
{
  int	i;

  i = 0;
  while (i < argc)
    {
      my_putstr(argv[argc - i - 1]);
      i = i + 1;
      my_putchar('\n');
    }
  return (0);
}