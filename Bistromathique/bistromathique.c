/*
** bistromathique.c for bistromathique in /home/uberti_l/rendu/Piscine_C_bistromathique
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 31 17:34:18 2015 louis-emile uberti-ares
** Last update Sat Oct 31 20:57:46 2015 louis-emile uberti-ares
*/

#include "include/bistromathique.h"
#include "include/my.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
  char	*expr;
  char	*operators;
  int	i;

  i = 0;
  expr = is_expr_valid(ac, av);
  if (sizeof(expr) != sizeof(get_expr(my_get_nbr(av[3]))))
    return (1);
  operators = malloc(my_strlen(av[2]));
  while (av[2][i] != EOS)
    {
      operators[i] = av[2][i];
      i = i + 1;
    }
  eval_expr(expr, operators);
  my_putchar(EOL);
  return (0);
}
