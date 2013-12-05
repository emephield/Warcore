/*
** gen_laby.h for cartographer in /home/keolas_s//test/prog_elem/cartographer/include
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Mon Oct 21 02:18:10 2013 souvisay keolasy
** Last update Thu Dec  5 08:47:25 2013 souvisay keolasy
*/

#ifndef		COREWAR_H_
# define	COREWAR_H_

# define	USAGE		"./corewar [FILE_NAME]\n"

# include	"boolean.h"

# define	INEXT	"cor"
# define	OUTEXT	"s"

# include	"op.h"
# define	GETTARG(x, i)	((x >> ((MAX_ARGS_NUMBER - i) * 2)) % 4)

typedef union		u_endian
{
  int			nb;
  char			str[4];
}			t_endian;

typedef struct		s_cmd
{
  struct s_cmd		*next;
  struct s_cmd		*prev;
  char			*name;
  int			size;
  char			cmd;
  unsigned char		param;
  int			arg[MAX_ARGS_NUMBER + 1];
}			t_cmd;

typedef	struct	s_file
{
  struct s_file	*next;
  t_cmd		*head;
  t_cmd		*tail;
  char		*path;
  char		*prog_name;
  char		*prog_com;
  int		fdin;
  int		fdout;
  t_bool	dead;
  t_bool	(*destroy)(struct s_file);
}		t_file;

typedef struct	s_ctrl
{
  t_file	*head;
  t_file	*tail;
}		t_ctrl;

t_bool		open_file(t_ctrl *ctrl, char **path);
t_bool		read_header(t_ctrl *ctrl);
t_bool		is_big_endian();
t_bool		read_file(t_ctrl *ctrl);
unsigned int	check_endianess(unsigned int nb, int len);

#endif		/* COREWAR_H_ */
