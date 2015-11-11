/*
** my_showstr.c for my_showstr in /home/uberti_l/rendu/Piscine_C_J07/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 20:46:28 2015 louis-emile uberti-ares
** Last update Wed Nov 11 22:22:10 2015 louis-emile uberti-ares
*/

int	my_putnbr_base(int nbr, char *base);
void	my_putchar(char c);

int	my_showstr(char *str)
{
  int	idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if ((str[idx] < 32) || (str[idx] > 126))
	{
	  my_putchar('\\');
	  if (str[idx] < 14)
	    my_putchar('0');
	  my_putnbr_base(str[idx], "0123456789abcdef");
	}
	else
	  my_putchar(str[idx]);
      idx = idx + 1;
    }
  return (0);
}
