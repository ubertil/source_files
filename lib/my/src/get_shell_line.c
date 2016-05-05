/*
** getnextline.c for getnextline in /home/uberti_l/rendu/Prog_elem/CPE_2015_getnextline
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Jan  7 20:14:26 2016 louis-emile uberti-ares
** Last update Thu May  5 14:52:21 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <unistd.h>

static int	my_strlen(const char *str)
{
  int		i;

  i = 0;
  while (*str)
    {
      str++;
      ++i;
    }
  return (i);
}

static char	*my_cpy(char *dest, const char *src)
{
  int		i;
  int		j;

  j = -1;
  i = 0;
  while (dest[i] != '\0')
    ++i;
  while (src[++j] != '\0')
    {
      dest[i] = src[j];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

static int		find_next_line(char *str)
{
  int			i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '\n')
      {
	str[i] = '\0';
	return (i);
      }
  return (-1);
}

static char		*my_str_realloc(char *str, const char **buffer)
{
  char			*new;

  if ((new = malloc(sizeof(char) *
		    (my_strlen(str) + my_strlen(*buffer) + 1))) == NULL)
    return (NULL);
  new[0] = '\0';
  new = my_cpy(new, str);
  new = my_cpy(new, *buffer);
  free(str);
  return (new);
}

char		*get_shell_line(const int fd)
{
  char		*buffer;
  char		*str;
  int		ret;

  if (((str = malloc(2)) == NULL) ||
      ((buffer = malloc(2)) == NULL))
    return (NULL);
  buffer[0] = '\0';
  str[0] = '\0';
  while ((ret = read(fd, buffer, 1)) > 0)
    {
      buffer[ret] = '\0';
      if ((str = my_str_realloc(str, &buffer)) == NULL)
	return (NULL);
      if (find_next_line(str) != -1)
	{
	  free(buffer);
	  return (str);
	}
    }
  free(buffer);
  free(str);
  return (NULL);
}
