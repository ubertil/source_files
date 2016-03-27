/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
<<<<<<< HEAD
** Last update Sat Mar 26 23:53:37 2016 louis-emile uberti-ares
=======
** Last update Mon Mar 21 16:34:28 2016 Louis-Emile Uberti
>>>>>>> 6162f7a51805b01874a25b2a1091a1f563a7c85d
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    write(1, &str[i++], 1);
}
