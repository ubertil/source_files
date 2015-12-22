// Jason Brillante "Damdoshi"
// Lisa Monpierre "Leeza"
// Pentacle Technologie 2009-2013
//
// DABSIC
// Developer's All-purpose Block Structured Instruction Code

#include	<stdlib.h>
#include	<string.h>
#include	"ParsingTools.hpp"

bool		bpt::ParsingTools::ReadInsideChar(const bpt::string	&str,
						  unsigned int		&index,
						  wchar_t		&out) const
{
  if (str[index] & 0x80) // Unicode character
    {
      unsigned int len;

      if ((len = strnlen(&str.c_str()[index], sizeof(out))) > sizeof(out))
	len = sizeof(out);
      memcpy(&out, &str.c_str()[index], len);
      if ((str[index] & 0xE0) == 0xC0) // 110x xxxx
	{
	  out &= 0xFFFF;
	  index += 2;
	}
      else if ((str[index] & 0xF0) == 0xE0) // 1110 xxxx
	{
	  out &= 0xFF;
	  index += 3;
	}
      else if ((str[index] & 0xF8) == 0xF0) // 1111 0xxx
	index += 4;
      else
	return (false);
      out = Endian(out);
      return (true);
    }
  else if (str[index] != WCP'\\')
    {
      out = str[index++];
      return (true);
    }
  index += 1;
  switch (str[index++])
    {
    case WCP'a':
      out = WCP'\a';
      return (true);
    case WCP'b':
      out = WCP'\b';
      return (true);
    case WCP'v':
      out = WCP'\v';
      return (true);
    case WCP'f':
      out = WCP'\f';
      return (true);
    case WCP'n':
      out = WCP'\n';
      return (true);
    case WCP't':
      out = WCP'\t';
      return (true);
    case WCP'\\':
      out = WCP'\\';
      return (true);
    case WCP'r':
      out = WCP'\r';
      return (true);
    case WCP'"':
      out = WCP'"';
      return (true);
    case WCP'\'':
      out = WCP'\'';
      return (true);
    case WCP'0':
      {
	unsigned int	i = index;

	ReadChar(str, index, Octal);
	bpt::string	sub = str.substr(i, index - i);
	std::string	num(sub.begin(), sub.end());

	out = strtoll(num.c_str(), NULL, 8);
	return (true);
      }
    default:
      return (false);
    }
  return (false);
}

