/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
** Last update Sat Mar 26 23:53:37 2016 louis-emile uberti-ares
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    write(1, &str[i++], 1);
}
