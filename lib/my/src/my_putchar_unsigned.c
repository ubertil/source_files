/*
** my_putchar_unsigned.c for my_putchar_unsigned in /home/uberti_l/rendu/Unix/PSU_2015_minitalk/tools
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Feb  3 11:37:04 2016 louis-emile uberti-ares
** Last update Wed Feb  3 11:37:40 2016 louis-emile uberti-ares
*/

#include <unistd.h>

void		my_putchar_unsigned(unsigned char c)
{
  write(1, &c, 1);
}
