/*
** endian.c for warcore in /home/keolas_s//test/prog_elem/new_korewar
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Nov 27 01:57:55 2013 souvisay keolasy
** Last update Tue Dec  3 09:23:39 2013 souvisay keolasy
*/

#include "boolean.h"
#include "tools.h"
#include "corewar.h"

t_bool		is_big_endian()
{
  int		i;
  unsigned char	*test;
  static t_bool endianess = 3;


  if (endianess == 3)
    {
      i = 0x12345678;
      test = (unsigned char*) (&i);
      if (*test == 0x78)
	endianess = TRUE;
      else
	endianess = FALSE;
    }
  return (endianess);
}

unsigned int	check_endianess(unsigned int nb, int len)
{
  t_endian	temp;

  if (is_big_endian() == TRUE)
    {
      temp.nb = nb;
      my_revmem(temp.str , len);
    }
  return ((unsigned int) temp.nb);
}
