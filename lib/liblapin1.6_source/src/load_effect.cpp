// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

t_bunny_effect		*bunny_load_effect(const char		*file)
{
  struct bunny_effect	*eff;

  if ((eff = new (std::nothrow) struct bunny_effect) == NULL)
    goto Fail;
  if ((eff->effect.loadFromFile(file)) == false)
    goto FailStruct;

  eff->sound.setBuffer(eff->effect);
  eff->type = EFFECT;

  return ((t_bunny_effect*)eff);

 FailStruct:
  delete eff;
 Fail:
  return (NULL);
}
