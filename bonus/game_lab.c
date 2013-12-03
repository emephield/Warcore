/*
** lab_aff.c for cartogrpher in /home/keolas_s//test/prog_elem/cartographer
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Tue Oct 22 09:39:30 2013 souvisay keolasy
** Last update Sun Nov 10 23:21:39 2013 souvisay keolasy
*/

#include <curses.h>
#include "boolean.h"
#include "gen_laby.h"

static t_arrow	g_tab_arrow[] =
  {
    {KEY_UP, &key_up},
    {KEY_DOWN, &key_down},
    {KEY_LEFT, &key_left},
    {KEY_RIGHT, &key_right},
    {0, NULL}
  };

static char	*g_labch[] = {"\0", " ", " ", " ", "M", "E", ".", "f"};

void	n_print_tab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  move(0, 0);
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if ((tab[i][j]) == WALL || (tab[i][j]) == DELIM)
	    {
	      attron(COLOR_PAIR(1));
	    }
	  printw(g_labch[(int) (tab[i][j])]);
	  if ((tab[i][j]) == WALL || (tab[i][j]) == DELIM)
	    {
	      attroff(COLOR_PAIR(1));
	    }
	  j++;
	}
      printw("\n");
      i++;
    }
}

t_bool		aff_lab(char **lab, t_opt *opt)
{
  int		nkey;
  int		i;

  n_print_tab(lab);
  refresh();
  move(opt->cur_x, opt->cur_y);
  while ((nkey = getch()) != '\033')
    {
      i = 0;
      refresh();
      while (g_tab_arrow[i].key != 0)
	{
	  if (nkey == g_tab_arrow[i].key &&
	      g_tab_arrow[i].fct(lab, opt, opt->size) == FALSE)
	    return (TRUE);
	  i++;
	}
      n_print_tab(lab);
      move(opt->cur_x, opt->cur_y);
      refresh();
      nkey = 0;
    }
  endwin();
  return (TRUE);
}
