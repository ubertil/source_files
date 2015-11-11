/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
** Last update Wed Nov 11 22:03:15 2015 louis-emile uberti-ares
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
