/*
** my_revstr.c for my_revstr in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 11:50:55 2015 louis-emile uberti-ares
** Last update Wed Oct  7 20:25:41 2015 louis-emile uberti-ares
*/

char	*my_revstr(char *str)
{
  char	revstr[] = "\n";
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      revstr[i] = str[i];
      i = i + 1;
    }
  i = i + 1;
  revstr[i] = '\0';
  while (i > 0)
    {
      str[i - 1] = revstr[count - 1];
      count = count + 1;
      i = i - 1;
    }
  return (str);
}
