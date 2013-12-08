/*
** main.c for korewar in /home/keolas_s//test/prog_elem/new_korewar
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Fri Nov 15 13:54:10 2013 souvisay keolasy
** Last update Sun Dec  8 03:09:30 2013 souvisay keolasy
*/

#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"
#include "my_errno.h"

int		main(int ac, char **av)
{
  t_ctrl	ctrl;
  t_cmd		*temp;

  ctrl.head = NULL;
  ctrl.tail = NULL;
  if (ac >= 2)
    {
      if (open_file(&ctrl, av + 1) == FALSE)
	return (FALSE);
      read_header(&ctrl);
      read_file(&ctrl);
      temp = ctrl.head->head;
      write_file(&ctrl);
      /* while (temp != NULL) */
      /* 	{ */
      /* 	  printf("%d\n", temp->cmd); */
      /* 	  temp = temp->next; */
      /* 	} */
    }
  else
    {
      print_error(USAGE);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
