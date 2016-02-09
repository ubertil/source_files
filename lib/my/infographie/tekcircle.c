/*
** tekcircle.c for tekcircle in /home/uberti_l/source_files/lib/my/infographie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Feb  9 19:15:19 2016 louis-emile uberti-ares
** Last update Tue Feb  9 20:25:28 2016 louis-emile uberti-ares
*/

#include <lapin.h>

void			drawcircle(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_bunny_position *tmp,
				   unsigned int col)
{
  unsigned int		*pt;

  pt = (unsigned int *)pix->pixels;
  pt[(pos->x + tmp->x) + ((pos->y + tmp->y) * pix->clipable.clip_width)] = col;
  pt[(pos->x + tmp->y) + ((pos->y + tmp->x) * pix->clipable.clip_width)] = col;
  pt[(pos->x - tmp->x) + ((pos->y + tmp->y) * pix->clipable.clip_width)] = col;
  pt[(pos->x - tmp->y) + ((pos->y + tmp->x) * pix->clipable.clip_width)] = col;
  pt[(pos->x + tmp->x) + ((pos->y - tmp->y) * pix->clipable.clip_width)] = col;
  pt[(pos->x + tmp->y) + ((pos->y - tmp->x) * pix->clipable.clip_width)] = col;
  pt[(pos->x - tmp->x) + ((pos->y - tmp->y) * pix->clipable.clip_width)] = col;
  pt[(pos->x - tmp->y) + ((pos->y - tmp->x) * pix->clipable.clip_width)] = col;
}

void			tekcircle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  double radius,
				  unsigned int color)
{
  t_bunny_position	current;
  int			d;

  current.x = 0;
  current.y = (unsigned int)radius;
  d = (unsigned int)radius - 1;
  while (current.y >= current.x)
    {
      drawcircle(pix, pos, &current, color);
      if (d >= 2 * current.x)
	d -= 2 * current.x++ + 1;
      else if (d < 2 * (radius - current.y))
	d += 2 * current.y-- - 1;
      else
	d += 2 * (current.y-- - current.x++ - 1);
    }
}
