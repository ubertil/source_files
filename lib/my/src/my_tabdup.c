/*
** my_tab_to_tab.c for my_tab_to_tab in /home/uberti_l
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jan 20 21:40:01 2016 louis-emile uberti-ares
** Last update Mon Mar 21 16:43:29 2016 Louis-Emile Uberti
*/

#include <stdlib.h>

char		**my_tab_to_tab(char **tab)
{
  int		i;
  char		**new;

  if (tab[0] == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    i += 1;
  if ((new = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      new[i] = my_strdup(tab[i]);
      i += 1;
    }
  new[i] = NULL;
  return (new);
}
