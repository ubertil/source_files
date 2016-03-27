/*
** my_putstr_err.c for my_putstr_err in /home/uberti_l/source_files/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Dec 12 08:11:29 2015 louis-emile uberti-ares
<<<<<<< HEAD:lib/my/src/my_puterr.c
** Last update Sat Mar 26 23:54:20 2016 louis-emile uberti-ares
=======
** Last update Mon Mar 21 12:53:25 2016 Louis-Emile Uberti
>>>>>>> 6162f7a51805b01874a25b2a1091a1f563a7c85d:lib/my/src/my_putstr_err.c
*/

#include <unistd.h>

void	my_puterr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
<<<<<<< HEAD:lib/my/src/my_puterr.c
    write(2, &str[i++], 1);
=======
    err_putchar(str[i++]);
>>>>>>> 6162f7a51805b01874a25b2a1091a1f563a7c85d:lib/my/src/my_putstr_err.c
}
