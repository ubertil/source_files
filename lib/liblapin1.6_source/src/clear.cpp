// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include		"lapin_private.h"

void			bunny_clear(t_bunny_buffer		*picture,
				    unsigned int		_color)
{
  size_t		*type = (size_t*)picture;
  sf::Color		color
    ((_color >> (RED_CMP * 8)) & 0xFF,
     (_color >> (GREEN_CMP * 8)) & 0xFF,
     (_color >> (BLUE_CMP * 8)) & 0xFF,
     (_color >> (ALPHA_CMP * 8)) & 0xFF
     );

  switch (*type)
    {
    case WINDOW:
      {
	struct bunny_window	*win = (struct bunny_window*)picture;

	win->window->clear(color);
	return ;
      }
    case GRAPHIC_RAM:
      {
	struct bunny_picture	*pic = (struct bunny_picture*)picture;

	pic->texture->clear(color);
	return ;
      }
    default:
      {
	t_bunny_pixelarray	*pix = (t_bunny_pixelarray*)picture;

	gl_bunny_my_clear(pix, _color);
	return ;
      }
    }
}
