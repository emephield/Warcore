/*
** read_file.c for warcore in /home/keolas_s//test/prog_elem/new_korewar
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Thu Nov 28 14:57:15 2013 souvisay keolasy
** Last update Sun Dec  8 03:19:14 2013 souvisay keolasy
*/

#include <stdlib.h>
#include "my_errno.h"
#include "boolean.h"
#include "corewar.h"
#include "tools.h"
#include "op.h"

extern op_t	op_tab[];

int	g_tabsize[][2] =
  {
    {0, 0}, 
    {1, 1}, 
    {2, DIR_SIZE}, 
    {3, IND_SIZE} 
  };

t_bool		read_arg(t_file *file, t_cmd *cmd)
{
  int		i;
  int		type;
  unsigned int	size;

  i = 1;
  while (i < MAX_ARGS_NUMBER && (type = GETTARG(cmd->param, i)) != 0)
    {
      if (cmd->cmd == 12 || cmd->cmd == 15 || cmd->cmd == 9)
	size = IND_SIZE;
      else
	size = g_tabsize[type][1];
      if ((cmd->cmd == 11 && (i == 2 || i == 3) && size >= 4) ||
	  (cmd->cmd == 10 && (i == 1 || i == 2) && size >= 4))
	size = 2;
      my_read(file->fdin, &cmd->arg[i - 1], size);
      cmd->arg[i - 1] = check_endianess(cmd->arg[i - 1], size);
      i++;
    }
  return (TRUE);
}

t_bool		read_param_arg(t_file *file, t_cmd *cmd)
{
  int	ret;

  if (op_tab[cmd->cmd - 1].nbr_args == 1 &&
      op_tab[cmd->cmd - 1].type[0] == T_DIR)
    cmd->param = 2 << 6;
  else if ((ret = my_read(file->fdin, &cmd->param, sizeof(cmd->param))) == 0)
    {
      print_error("Corrupted commande\n");
      file->dead = TRUE;
      return (TRUE);
    }
  return (((ret == -1) ? (FALSE) : (TRUE)));
}

t_bool		read_command(t_file *file)
{
  int		temp;
  int		ret;
  t_cmd		*cmd;

  temp = 0;
  while ((ret = my_read(file->fdin, &temp, 1)) > 0)
    {
      if ((cmd = my_malloc(sizeof(*cmd))) == NULL)
	return (FALSE);
      cmd->cmd = temp;
      if (cmd->cmd >= 1 && cmd->cmd <= 16)
	{
	  if (read_param_arg(file, cmd) == FALSE)
	    return (FALSE);
      	  if (read_arg(file, cmd) == FALSE)
	    return (FALSE);
	  if (file->head == NULL)
	    file->head = cmd;
	  if (file->tail != NULL)
	    {
	      file->tail->next = cmd;
	      cmd->prev = file->tail;
	    }
	  file->tail = cmd;
	}
    }
  return (((ret == -1) ? (FALSE) : (TRUE)));
}

t_bool		read_file(t_ctrl *ctrl)
{
  t_file	*cur;

  cur = ctrl->head;
  while (cur != NULL)
    {
      if (cur->dead == FALSE)
	read_command(cur);
      cur = cur->next;
    }
  return (TRUE);
}
