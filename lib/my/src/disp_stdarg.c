/*
** disp_stdarg.c for disp_stdarg in /home/uberti_l/rendu/PSU_2015_my_printf_bootstrap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Nov  4 11:33:38 2015 louis-emile uberti-ares
** Last update Sat Dec 12 08:11:12 2015 louis-emile uberti-ares
*/

#include <stdarg.h>

void		my_putchar(char c);
int		my_putstr(char *str);
int		my_put_nbr(int nbr);

int		disp_stdarg(char *s, ...)
{
  int		idx;
  va_list	list;

  idx = 0;
  va_start(list, s);
  while (s[idx] != '\0')
    {
      if (s[idx] == 'c')
	my_putchar(va_arg(list, int));
      if (s[idx] == 's')
	my_putstr(va_arg(list, char *));
      if (s[idx] == 'i')
	my_put_nbr(va_arg(list, int));
      my_putchar('\n');
      idx = idx + 1;
    }
  va_end(list);
  return (0);
}
