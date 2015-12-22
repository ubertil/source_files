/*
** my_strlcat.c for my_strlcat in /home/uberti_l/rendu/Piscine_C_J07/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 20:51:01 2015 louis-emile uberti-ares
** Last update Tue Dec 22 11:13:46 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	size_dest;

  size_dest = my_strlen(dest);
  if (size < size_dest)
    return (size + size_dest);
  i = 0;
  while (src[i] != '\0' && (i + size_dest < size))
    {
      dest[i + size_dest] = src[i];
      i += 1;
    }
  if ((i + size_dest < size))
    dest[i + size_dest] = '\0';
  else
    dest[i + size_dest - 1] = '\0';
  return (size_dest + my_strlen(src));
}
