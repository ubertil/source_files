/*
** my_sort_int_tab.c for my_sort_int_tab in /home/uberti_l/rendu/Piscine_C_J07/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 20:15:56 2015 louis-emile uberti-ares
** Last update Sun Mar 27 00:02:34 2016 louis-emile uberti-ares
*/

int	*my_sort_int_tab(int *tab, int size)
{
  int	swap;
  int	i;
  int	sorted;

  i = 0;
  while (i < size)
    {
      if (tab[i] > tab[i + 1])
	{
	  swap = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = swap;
	  sorted = 1;
	}
      i += 1;
    }
  return (tab);
}
