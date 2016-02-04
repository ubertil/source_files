/*
** tekisoproject.c for tekisoproject in /home/uberti_l/rendu/info/tcore
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Dec 20 17:49:22 2015 louis-emile uberti-ares
** Last update Tue Dec 22 13:01:43 2015 louis-emile uberti-ares
*/

#include <lapin.h>
#include <math.h>

void	tekisoproject(t_bunny_position *out,
		      int x, int y, int z)
{
  out->x = (sqrt(2) / 2) * (x + y);
  out->y = sqrt((2 / 3) * z) - ((1 / sqrt(6)) * (x - y));
}
