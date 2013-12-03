/*
** bonus_algo_gen.c for cartographer in /home/keolas_s//test/test/cartographer2
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sun Nov 10 22:26:31 2013 souvisay keolasy
** Last update Sun Nov 10 22:26:59 2013 souvisay keolasy
*/

#define  _BSD_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include "gen_laby.h"
#include "tools.h"

static	char	g_defsign[] = {-1, 1};

static	void	opt_show(char **tab, t_opt *opt)
{
  if (opt->game == TRUE)
    {
      n_print_tab(tab);
      refresh();
    }
  else
    {
      my_putstr("\033[H");
      print_tab(tab, TRUE);
    }
  usleep(SLEEP_SIZE);
}

unsigned int	count_inter(char **tab, int x, int y)
{
  int		ret;

  ret = 0;
  if (tab[x - 1][y] == WAY)
    ret++;
  if (tab[x + 1][y] == WAY)
    ret++;
  if (tab[x][y + 1] == WAY)
    ret++;
  if (tab[x][y - 1] == WAY)
    ret++;
  return (ret);
}

unsigned int	count_poss(char **tab, int x, int y)
{
  int		ret;

  ret = 0;
  if (tab[x - 1][y] == WALL && count_inter(tab, x - 1, y) < 2)
    ret++;
  if (tab[x + 1][y] == WALL && count_inter(tab, x + 1, y) < 2)
    ret++;
  if (tab[x][y + 1] == WALL && count_inter(tab, x, y + 1) < 2)
    ret++;
  if (tab[x][y - 1] == WALL && count_inter(tab, x, y - 1) < 2)
    ret++;
  return (ret);
}

char	**algo_gen(char **tab, int x, int y, t_opt *opt)
{
  int	addx;
  int	addy;

  addx = -1;
  addy = -1;
  while (count_poss(tab, x, y) != 0)
    {
      while (addx < 1 || addy < 1 || addx > opt->size || addy > opt->size ||
	     tab[addx][addy] != WALL || count_inter(tab, addx, addy) >= 2)
	{
	  addx = x;
	  addy = y;
	  if (rand() % 2 == 0)
	    addx = x +  (1 * g_defsign[rand() % 2]);
	  else
	    addy = y +  (1 * g_defsign[rand() % 2]);
	}
      tab[addx][addy] = WAY;
      if (opt->show == TRUE)
	opt_show(tab, opt);
      algo_gen(tab, addx, addy, opt);
    }
  return (tab);
}

char	**start_gen(char **tab, t_opt *opt, char mid)
{
  char	**temp;

  opt->cur_x = (rand() % opt->size) + 1;
  opt->cur_y = (rand() % opt->size) + 1;
  if (rand() % 2 == 0)
    {
      opt->cur_x = 1;
      tab[0][opt->cur_y] = ENTER;
    }
  else
    {
      opt->cur_y = 1;
      tab[opt->cur_x][0] = ENTER;
    }
  tab[opt->cur_x][opt->cur_y] = WAY;
  temp = algo_gen(tab, opt->cur_x, opt->cur_y, opt);
  tab[(opt->size / 2) + 1][(opt->size / 2) + 1] = mid;
  return (temp);
}
