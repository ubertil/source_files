/*
** sum_params.c for sum_params in /home/uberti_l/rendu/Piscine_C_J08/ex_02
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 16:24:04 2015 louis-emile uberti-ares
** Last update Tue Dec 22 10:45:02 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
int	my_putstr(char *str);

int	my_malloc(int argc, char **argv)
{
  int	lenght;
  int	count;
  int	i;

  lenght = 0;
  i = 0;
  count = 0;
  while (argc > i)
    {
      count = 0;
      while (argv[count][lenght] != '\0')
	lenght = lenght + 1;
      count = count + 1;
      lenght = lenght + 1;
      i = i + 1;
    }
  return (lenght);
}

char	*sum_params(int argc, char **argv)
{
  int	i;
  char	*src;
  int	a;
  int	b;

  i = 0;
  a = 0;
  b = 0;
  if ((src = malloc(my_malloc(argc, argv))) == NULL)
    return (NULL);
  while (argc > i)
    {
      b = 0;
      while (argv[i][b] != '\0')
	{
	  src[a] = argv[i][b];
	  b = b + 1;
	  a = a + 1;
	}
      i = i + 1;
      src[a] = '\n';
      a = a + 1;
    }
  src[a] = '\0';
  return (src);
}
