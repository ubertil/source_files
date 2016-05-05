/*
** my_putstr_err.c for my_putstr_err in /home/uberti_l/source_files/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Dec 12 08:11:29 2015 louis-emile uberti-ares
** Last update Thu May  5 14:53:28 2016 louis-emile uberti-ares
*/

#include <unistd.h>

int	my_puterr(const char *str)
{
  while (*str)
    write(2, str++, 1);
  return (-1);
}
