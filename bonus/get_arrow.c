/*
** get_arrow.c for cartographer in /home/keolas_s//test/prog_elem/cartographer
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Oct 22 09:47:33 2013 souvisay keolasy
** Last update Sun Nov 10 23:22:05 2013 souvisay keolasy
*/

#include <unistd.h>
#include <curses.h>
#include "tools.h"
#include "gen_laby.h"

static t_bool	end_game()
{
  clear();
  printw("VICTORY\n");
  refresh();
  sleep(3);
  return (FALSE);
}

t_bool	key_up(char **lab, t_opt *opt, int size)
{
  UNUSED(size);
  if (opt->cur_x > 1 && lab[opt->cur_x - 1][opt->cur_y] == WAY)
    opt->cur_x--;
  else if (opt->cur_x > 1 && lab[opt->cur_x - 1][opt->cur_y] == MINOTARUS)
    return (end_game());
  return (TRUE);
}

t_bool	key_down(char **lab, t_opt *opt, int size)
{
  if (opt->cur_x <= size && lab[opt->cur_x + 1][opt->cur_y] == WAY)
    opt->cur_x++;
  else if (opt->cur_x <= size && lab[opt->cur_x + 1][opt->cur_y] == MINOTARUS)
    return (end_game());
  return (TRUE);
}

t_bool	key_left(char **lab, t_opt *opt, int size)
{
  UNUSED(size);
  if (opt->cur_y > 1 && lab[opt->cur_x][opt->cur_y - 1] == WAY)
    opt->cur_y--;
  else if (opt->cur_y > 1 && lab[opt->cur_x][opt->cur_y - 1] == MINOTARUS)
    return (end_game());
  return (TRUE);
}

t_bool	key_right(char **lab, t_opt *opt, int size)
{
  if (opt->cur_y <= size && lab[opt->cur_x][opt->cur_y + 1] == WAY)
    opt->cur_y++;
  else if (opt->cur_y <= size && lab[opt->cur_x][opt->cur_y + 1] == MINOTARUS)
    return (end_game());
  return (TRUE);
}
