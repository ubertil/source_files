// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

t_bunny_ini		*bunny_load_ini(const char		*file)
{
  bpt::Ini		*ini = new (std::nothrow) bpt::Ini;

  if (ini == NULL)
    return (NULL);
  std::string		fil = file;

  try
    {
      if (ini->Load(fil) == false)
	{
	  delete ini;
	  return (NULL);
	}
    }
  catch (...)
    {
      return (NULL);
    }
  return ((t_bunny_ini*)ini);
}
