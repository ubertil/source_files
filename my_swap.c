/*
** my_swap.c for my_swap in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:55:36 2015 louis-emile uberti-ares
** Last update Wed Oct  7 20:08:41 2015 louis-emile uberti-ares
*/

int	my_swap(int *a, int *b)
{
  int	bin;

  bin = *b;
  *b = *a;
  *a = bin;
}
