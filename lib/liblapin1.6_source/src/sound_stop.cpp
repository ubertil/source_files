// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

void			bunny_sound_stop(t_bunny_sound		*sound)
{
  enum _music_or_sound	*type = (enum _music_or_sound*)sound;

  if (*type == MUSIC)
    ((struct bunny_music*)sound)->music.stop();
  else
    ((struct bunny_effect*)sound)->sound.stop();
}
