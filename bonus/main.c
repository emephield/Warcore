/*
** main.c for cartographer in /home/keolas_s//test/prog_elem/cartographer
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Mon Oct 21 02:20:24 2013 souvisay keolasy
** Last update Sun Nov 10 23:21:10 2013 souvisay keolasy
*/

#include <stdlib.h>
#include <time.h>
#include "tools.h"
#include "gen_laby.h"
#include "boolean.h"

void	init_main(t_opt *opt)
{
  srand(time(NULL));
  opt->game = FALSE;
  opt->show = FALSE;
}

int	main(int ac, char **av)
{
  char	**tab;
  t_opt	opt;

  if (ac >= 2)
    {
      init_main(&opt);
      if ((get_opt(av + 1, &opt)) == FALSE)
	return (EXIT_FAILURE);
      if ((tab = init_lab(opt.size)) == NULL)
	return (EXIT_FAILURE);
      tab = start_gen(tab, &opt, MINOTARUS);
      if (opt.game == FALSE)
	print_tab(tab, TRUE);
      else
	aff_lab(tab, &opt);
    }
  else
    {
      my_putstr(USAGE2);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
