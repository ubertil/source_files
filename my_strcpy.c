/*
** my_strcpy.c for my_strcpy in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 09:35:33 2015 louis-emile uberti-ares
** Last update Wed Oct  7 20:23:32 2015 louis-emile uberti-ares
*/

int	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 2;
      dest[i] = '\0';
      i = i - 1;
    }
  return (dest);
}
