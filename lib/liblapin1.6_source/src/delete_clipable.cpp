// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include			"lapin_private.h"

void				bunny_delete_clipable(t_bunny_clipable	*clip)
{
  size_t			*type = (size_t*)clip;

  switch (*type)
    {
    case GRAPHIC_RAM:
      {
	struct bunny_picture	*pic = (struct bunny_picture*)clip;

	delete pic->texture;
	delete pic;
	return ;
      }
    case SYSTEM_RAM:
      {
	struct bunny_pixelarray	*pic = (struct bunny_pixelarray*)clip;

	bunny_free(pic->rawpixels);
	delete pic;
	return ;
      }
    default:
      return ;
    }
}
