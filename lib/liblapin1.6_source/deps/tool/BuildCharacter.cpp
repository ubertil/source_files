// Jason Brillante "Damdoshi"
// Lisa Monpierre "Leeza"
// Pentacle Technologie 2009-2013
//
// DABSIC
// Developer's All-purpose Block Structured Instruction Code

#include	<string.h>
#include	"ParsingTools.hpp"

bpt::string	bpt::ParsingTools::BuildCharacter(wchar_t	c,
						  bool		in_string,
						  int		*out) const
{
  if (out)
    *out = 1;
  switch (c)
    {
    case WCP'\a':
      return (WCP"\\a");
    case WCP'\b':
      return (WCP"\\b");
    case WCP'\v':
      return (WCP"\\v");
    case WCP'\f':
      return (WCP"\\f");
    case WCP'\n':
      return (WCP"\\n");
    case WCP'\t':
      return (WCP"\\t");
    case WCP'\r':
      return (WCP"\\r");
    case WCP'\0':
      return (WCP"\\0");
    case WCP'\'':
      if (in_string)
	return (WCP"'");
      return (WCP"\\'");
    case WCP'"':
      if (in_string == false)
	return (WCP"\"");
      return (WCP"\\\"");
    default:
      bpt::stringstream ss;
      char		tab[sizeof(wchar_t) + 1];
      wchar_t		x;

      x = Endian(c);
      memcpy(&tab[0], &x, sizeof(x));
      tab[sizeof(x)] = '\0';
      if (tab[0] & 0x80)
	{
	  ss << &tab[0];
	  if (out)
	    *out = strlen(&tab[0]);
	}
      else
	{
	  char		_c = c;

	  if (c < WCP' ' || (c >= 127 && c <= 255))
	    ss << WCP"\\0" << std::oct << c;
	  else
	    ss << _c;
	}
      return (ss.str());
    }
  return (WCP"");
}

