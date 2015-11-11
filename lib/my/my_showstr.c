/*
** my_showstr.c for my_showstr in /home/uberti_l/rendu/Piscine_C_J07/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 20:46:28 2015 louis-emile uberti-ares
** Last update Wed Nov 11 22:06:03 2015 louis-emile uberti-ares
*/

int	my_putnbr_base(int nbr, char *base);
int	my_str_isprintable(char *str);
void	my_putchar(char c);

int	my_showstr(char *str)
{
  int	idx;
  char	to_verify[2];

  idx = 0;
  to_verify[1] = '\0';
  while (str[idx] != '\0')
    {
      to_verify[0] = str[idx];
      if (my_str_isprintable(to_verify))
	{
	  my_putchar('\\');
	  if (str[i] < 31)
	    my_putchar('0');
	  my_putnbr_base(str[idx], "0123456789abcdef");
	}
	else
	  my_putchar(str[idx]);
	idx = idx + 1;
    }
}
