/*
** cat.c for cat in /home/uberti_l/rendu/Piscine_C_J12/cat
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct 13 10:15:29 2015 louis-emile uberti-ares
** Last update Tue Oct 13 15:59:03 2015 louis-emile uberti-ares
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int	my_cat(char *str)
{
  int	fd;
  int	ret;
  char	buffer[1];

  fd = open(str, O_RDONLY);
  if (fd == -1)
    {
      my_putstr("open error\n");
      return (1);
    }
  ret = 1;
  while (ret != 0)
    {
      ret = read(fd, buffer, 1);
      if (ret != 0)
	{
	  my_putchar(buffer[0]);
	}
    }
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      my_cat(av[i]);
      i = i + 1;
    }
}
