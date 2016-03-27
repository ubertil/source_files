/*
** my_getnbr.c for my_getnbr in /home/uberti_l/rendu/Piscine_C_J04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Oct  9 11:44:36 2015 louis-emile uberti-ares
<<<<<<< HEAD
** Last update Sat Mar 26 23:52:31 2016 louis-emile uberti-ares
=======
** Last update Mon Mar 21 15:02:50 2016 Louis-Emile Uberti
>>>>>>> 6162f7a51805b01874a25b2a1091a1f563a7c85d
*/

int	my_get_lenght(char *str)
{
  int	lenght;
  int	i;

  lenght = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
	lenght = lenght * 10;
      i = i + 1;
    }
  if (lenght != 1)
    lenght = lenght / 10;
  return (lenght);
}

int	my_getnbr(char *str)
{
  int	lenght;
  int	nb;
  int	rang;

  rang = 0;
  lenght = my_get_lenght(str);
  nb = 0;
  while ((str[rang] != '\0') && (lenght != 0))
    {
      if ((str[rang] >= '0') && (str[rang] <= '9'))
	{
	  nb = nb + lenght * (str[rang] - 48);
	  lenght = lenght / 10;
	}
      rang = rang + 1;
    }
  if (str[0] == '-')
    return (-nb);
  return (nb);
}
