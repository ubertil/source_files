/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
** Last update Thu May  5 14:54:20 2016 louis-emile uberti-ares
*/

#include <unistd.h>

void	my_putstr(const char *str)
{
  while (*str)
    write(1, str++, 1);
}
