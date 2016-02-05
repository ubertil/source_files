/*
** skill_test.h for skill_test in /home/uberti_l/source_files/lib/my/infographie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Feb  5 14:40:42 2016 louis-emile uberti-ares
** Last update Fri Feb  5 14:43:33 2016 louis-emile uberti-ares
*/

#ifndef SKILL_TEST_H_
# define SKILL_TEST_H_
#include <lapin.h>

typedef struct		s_test
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_test;

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);

#endif /* SKILLTEST_H_ */
