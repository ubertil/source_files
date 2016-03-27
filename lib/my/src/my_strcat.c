/*
** my_strcat.c for my_strcat in /home/uberti_l/rendu/Piscine_C_J07/ex_02
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct  6 17:39:09 2015 louis-emile uberti-ares
** Last update Sun Mar 27 00:06:46 2016 louis-emile uberti-ares
*/

#include <stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  j = 0;
  if ((new = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i += 1;
    }
  while (src[j] != '\0')
    {
      new[i] = src[j];
      i += 1;
      j += 1;
    }
  new[i] = '\0';
  return (new);
}
