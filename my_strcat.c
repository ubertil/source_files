/*
** my_strcat.c for my_strcat in /home/uberti_l/rendu/Piscine_C_J07/ex_02
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct  6 17:39:09 2015 louis-emile uberti-ares
** Last update Wed Oct  7 16:45:36 2015 louis-emile uberti-ares
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (dest[a] != '\0')
    {
      a = a + 1;
    }
  while (src[i] != '\0')
    {
      src[i - 1] = '\0';
      dest[a] = src[i];
      a = a + 1;
      i = i + 1;
    }
  return (dest);
}
