/*
** my_strncpy.c for my_strncpy in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 10:50:19 2015 louis-emile uberti-ares
** Last update Wed Oct  7 20:25:58 2015 louis-emile uberti-ares
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while ((i < n) && (src[i] != '\0'))
    {
      dest[i] = src[i];
      i = i + 1;
      dest[n] = '\0';
    }
  return (dest);
}
