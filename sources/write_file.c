/*
** write_file.c for warcore in /home/keolas_s//git/warcore
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sun Dec  8 03:03:02 2013 souvisay keolasy
** Last update Sun Dec  8 03:19:27 2013 souvisay keolasy
*/

#include <stdlib.h>
#include "op.h"
#include "boolean.h"
#include "corewar.h"

extern op_t	op_tab[];

t_bool		write_file(t_ctrl *ctrl)
{
   t_cmd	*temp;
   int		i;
   int		type;

   temp = ctrl->head->head;
   while (temp != NULL)
     {
       i = 1;
       printf("%s\t", op_tab[temp->cmd - 1].mnemonique);
       while (i < MAX_ARGS_NUMBER && (type = GETTARG(temp->param, i)) != 0)
	 {
	   if (i != 1)
	     printf(",");
	   if (type == 2)
	     printf("%c", DIRECT_CHAR);
	   printf("%d", temp->arg[i - 1]);
	   i++;
	 }
       printf("\n");
       temp = temp->next;
     }
}
