/*
** my_getnbr.c for my_getnbr in /home/uberti_l/rendu/Piscine_C_J04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Oct  9 11:44:36 2015 louis-emile uberti-ares
** Last update Fri Oct  9 21:45:56 2015 louis-emile uberti-ares
*/

int	my_get_sign(char *str)
{
  int	i;
  int	sign;

  i = 0;
  sign = 1;
  while ((str[sign] != '\0') && ( i == 0))
    {
      if ((str[sign] >= 48) && (str[sign] <= 57))
	{
	  i = i + 1;
	}
      sign = sign + 1;
    }
  if (str[sign - 2] == 45)
    {
      sign = 2;
    }
  else
    {
      sign = 1;
    }
  return (sign);
}

int	my_get_lenght(char *str)
{
  int	lenght;
  int	i;

  lenght = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if (((str[i] < 48) && (str[i] > 57)) && (lenght == 1))
	{
	  i = i + 1;
	}
      if ((str[i] >= 48) && (str[i] <= 57))
	{
	  lenght = lenght * 10;
	}
      if (((str[i + 1] < 48) || (str[i + 1] > 57)) && (lenght > 1))
	{
	  break;
	}
      i = i + 1;
    }
  if (lenght != 1)
    {
      lenght = lenght / 10;
    }
  return (lenght);
}

int	my_getnbr(char *str)
{
  int	lenght;
  int	i;
  int	nb;
  int	rang;

  i = 0;
  rang = 0;
  lenght = my_get_lenght(str);
  nb = 0;
  while ((str[rang] != '\0') && (lenght != 0))
    {
      if ((str[rang] >= 48) && (str[rang] <= 57))
	{
	  nb = nb + lenght * (str[rang] - 48);
	  lenght = lenght / 10;
	}
      rang = rang + 1;
    }
  return (nb);
}

int	my_disp_sign(char *str)
{
  int	sign;
  int	nb;

  sign = my_get_sign(str);
  nb = my_get_nbr(str);
  if (sign == 2)
    {
      nb = nb * -1;
      return (nb);
    }
  if (sign == 1)
    {
      return (nb);
    }
}
