// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

void			bunny_delete_sound(t_bunny_sound		*sound)
{
  enum _music_or_sound	*type = (enum _music_or_sound*)sound;

  if (*type == MUSIC)
    delete ((struct bunny_music*)sound);
  else
    delete ((struct bunny_effect*)sound);
}
