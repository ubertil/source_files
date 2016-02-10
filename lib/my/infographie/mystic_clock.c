/*
** mystic_clock.c for mystic_clock in /home/uberti_l/rendu/Infographie/skill_test/mystic_2020
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Feb 10 13:17:29 2016 louis-emile uberti-ares
** Last update Wed Feb 10 15:07:41 2016 louis-emile uberti-ares
*/

#include <lapin.h>
#include <math.h>
#include "skill_test.h"

void			mystic_clock(t_bunny_pixelarray *pix,
				     const t_bunny_circle *circle,
				     double angle,
				     size_t depth)
{
  size_t		i;
  t_color		col;
  t_bunny_circle	new;

  i = 0;
  new.position = circle->position;
  new.radius = circle->radius;
  col.full = circle->color;
  while (i < depth)
    {
      tekcircle(pix, &new.position, new.radius, new.color);
      new.position.x += cos(-angle) * new.radius;
      new.position.y += sin(-angle) * new.radius;
      col.argb[RED_CMP] = 255 - col.argb[RED_CMP];
      col.argb[BLUE_CMP] = 255 - col.argb[BLUE_CMP];
      col.argb[GREEN_CMP] = 255 - col.argb[GREEN_CMP];
      new.color = col.full;
      new.radius = new.radius / 2.;
      angle = 2 * (-angle);
      i += 1;
    }
}
