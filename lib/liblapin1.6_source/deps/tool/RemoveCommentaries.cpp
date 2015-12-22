// Jason Brillante "Damdoshi"
// Lisa Monpierre "Leeza"
// Pentacle Technologie 2009-2013
//
// DABSIC
// Developer's All-purpose Block Structured Instruction Code

#include	"ParsingTools.hpp"

void		bpt::ParsingTools::RemoveCommentaries(bpt::string	&str) const
{
  unsigned int	i;

  i = 0;
  while (str[i] != WCP'\0')
    if (str.compare(i, 2, WCP"//") == 0)
      for (;str[i] != WCP'\0' && str[i] != WCP'\n'; ++i)
	str[i] = WCP' ';
    else if (str.compare(i, 2, WCP"/*") == 0)
      {
	for (;str[i] != WCP'\0' && str.compare(i, 2, WCP"*/") != 0; ++i)
	  str[i] = WCP' ';
	if (str[i] != WCP'\0')
	  {
	    str[i++] = WCP' ';
	    str[i++] = WCP' ';
	  }
      }
    else
      i += 1;
}
