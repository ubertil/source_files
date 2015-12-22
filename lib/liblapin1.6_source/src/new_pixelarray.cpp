// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include			"lapin_private.h"

t_bunny_pixelarray		*bunny_new_pixelarray(unsigned int		width,
						      unsigned int		height)
{
  struct bunny_pixelarray	*pa;
  unsigned int			i;

  if ((pa = new (std::nothrow) struct bunny_pixelarray) == NULL)
    goto Fail;
  if ((pa->rawpixels = (unsigned int*)bunny_malloc(width * height * sizeof(*pa->rawpixels))) == NULL)
    goto FailStruct;
  for (i = 0; i < width * height; ++i)
    pa->rawpixels[i] =
      255 << (RED_CMP * 8) |
      105 << (GREEN_CMP * 8) |
      180 << (BLUE_CMP * 8) |
      255 << (ALPHA_CMP * 8)
      ;
  pa->image.create(width, height, sf::Color(255, 105, 180, 255));

  pa->type = SYSTEM_RAM;
  pa->rect.left = 0;
  pa->rect.top = 0;
  pa->rect.width = pa->width = width;
  pa->rect.height = pa->height = height;
  pa->sprite.setTexture(pa->tex);
  pa->x_origin = 0;
  pa->y_origin = 0;
  pa->x_scale = 1;
  pa->y_scale = 1;
  pa->rotation = 0;

  return ((t_bunny_pixelarray*)pa);

 FailStruct:
  delete pa;
 Fail:
  return (NULL);
}
