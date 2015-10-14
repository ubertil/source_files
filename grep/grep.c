/*
** grep.c for grep in /home/uberti_l/rendu/Piscine_C_J12/grep
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct 13 10:16:25 2015 louis-emile uberti-ares
** Last update Tue Oct 13 15:01:49 2015 louis-emile uberti-ares
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	my_grep(char *to_find, char *str, int size)
{
  int	fd;
  int	ret;
  char	buffer[1];
  int	i;

  i = 0;
  fd = open(str, O_RDONLY);
  if (fd == -1)
    {
      my_putstr("open error\n");
      return (1);
    }
  ret = 1;
  while (ret !=0)
    {
      ret = read(fd, buffer, 1);
      if (i >= size)
	{
	  my_putchar(buffer[0]);
	}
      if ((ret != 0) && ((to_find[i] == buffer[0]) || (i >= size)))
	{
	  i = i + 1;
	}
      else
	{
	  i = 0;
	}
    }
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;

  i = 2;
  while (i < ac)
    {
      my_grep(av[1], av[i], my_strlen(av[1]));
      i = i + 1;
    }
}
