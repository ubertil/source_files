// Jason Brillante "Damdoshi"
// Lisa Monpierre "Leeza"
// Pentacle Technologie 2009-2013
//
// DABSIC
// Developer's All-purpose Block Structured Instruction Code

#include	"ParsingTools.hpp"

bool		bpt::ParsingTools::ReadWhitespace(const bpt::string	&str,
						  unsigned int		&index) const
{
  unsigned int	_index;

  _index = index;
  while (ReadChar(str, index, WCP" \t") ||
	 ReadText(str, index, WCP"\\\r\n") ||
	 ReadText(str, index, WCP"\\\n") ||
	 ReadText(str, index, WCP"\\\r"));
  return (_index != index);
}
