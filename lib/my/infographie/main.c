/*
** main.c for main in /home/uberti_l/rendu/Infographie/skill_test/chromatic_2020
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Feb  5 15:14:51 2016 louis-emile uberti-ares
** Last update Fri Feb  5 16:22:04 2016 louis-emile uberti-ares
*/

#include <lapin.h>

int			main(void)
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;

  win = bunny_start(800,600, false, "TEST");
  pix = bunny_new_pixelarray(800, 600);
  bunny_blit(&win->buffer, &pix->clipable, NULL);
  bunny_display(win);
  bunny_loop(win, 25, NULL);
  bunny_delete_clipable(&pix->clipable);
  bunny_stop(win);
  return (0);
}
