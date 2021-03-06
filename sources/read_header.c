/*
** read_header.c for warcore in /home/keolas_s//test/prog_elem/new_korewar/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Nov 27 01:30:07 2013 souvisay keolasy
** Last update Tue Dec  3 02:41:48 2013 souvisay keolasy
*/

#include <stdlib.h>
#include "corewar.h"
#include "boolean.h"
#include "op.h"
#include "tools.h"
#include "my_errno.h"

t_bool		check_header(t_file *cur, header_t *header)
{
  t_endian	temp;

  temp.nb = header->magic;
  if (is_big_endian() == TRUE)
    my_revmem(temp.str , 4);
  if (temp.nb != COREWAR_EXEC_MAGIC)
    {
      print_error("Invalid magic number in ");
      print_error(cur->path);
      print_error("\n");
      cur->dead = TRUE;
      return (FALSE);
    }
  return (TRUE);
}
t_bool		read_header(t_ctrl *ctrl)
{
  t_file	*cur;
  header_t	header;

  cur = ctrl->head;
  while (cur != NULL)
    {
      if (my_read(cur->fdin, &header, sizeof(header)) == -1)
	return (FALSE);
      check_header(cur, &header);
      if ((cur->prog_name = my_strndup(header.prog_name,
				       PROG_NAME_LENGTH + 1)) == NULL)
	return (FALSE);
      if ((cur->prog_com = my_strndup(header.comment,
				     COMMENT_LENGTH + 1)) == NULL)
	return (FALSE);      
      cur = cur->next;
    }
  return (TRUE);
}
