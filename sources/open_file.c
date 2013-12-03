/*
** open_file.c for corewar in /home/keolas_s//test/prog_elem/new_korewar/sources
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Sun Nov 17 12:00:43 2013 souvisay keolasy
** Last update Thu Nov 28 14:44:25 2013 souvisay keolasy
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "tools.h"
#include "my_errno.h"

t_bool	check_access(char *path)
{
  if (access(path, F_OK) == -1)
    {
      print_error("File ");
      print_error(path);
      print_error(" doesn't exist.\n");
      return (FALSE);
    }
  if (access(path, R_OK) == -1)
    {
      print_error("Missing read right on ");
      print_error(path);
      print_error(".\n");
      return (FALSE);
    }
  return (TRUE);
}

t_bool		check_ext(char *ext, char *path, t_file **file)
{
  char		*temp_ext;
  char		*temp_path;
  t_bool	ret;

  if ((temp_ext = my_strdup(ext)) == FALSE)
      return (FALSE);
  if ((temp_path = my_strdup(path)) == FALSE)
      return (FALSE);
  if ((my_strcmp(my_revstr(temp_path), my_revstr(temp_ext))) != '.')
    {
      if ((temp_path = my_stradd(my_stradd(path, "."), ext)) == NULL)
	return (FALSE);
      path = temp_path;
    }
  ret = check_access(path);
  free(temp_ext);
  free(temp_path);
  if ((*file = my_malloc(sizeof(**file))) == FALSE)
      return (FALSE);
  if (ret == TRUE && ((*file)->path = my_strdup(path)) == NULL)
    return (FALSE);
  return (ret);
}

t_bool	open_io(t_file *file, t_ctrl *ctrl)
{
  char	*temp_out;
  char	*out_exten;

  if ((out_exten = my_stradd(".", OUTEXT)) == NULL)
    return (FALSE);
  if ((file->fdin = my_open(file->path, O_RDONLY)) == -1)
    return (FALSE);
  if ((temp_out = my_stradd(my_strndup(file->path, my_strlen(file->path)
				       - (my_strlen(INEXT) + 1)),
			    out_exten)) == NULL)
    return (FALSE);
  if ((file->fdout = my_create(temp_out,
			       O_WRONLY | O_TRUNC,
			       S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)) == -1)
    return (FALSE);
  if (ctrl->head == NULL)
    ctrl->head = file;
  if (ctrl->tail != NULL)
    ctrl->tail->next = file;
  ctrl->tail = file;
  free(out_exten);
  return (TRUE);
}

t_bool	open_file(t_ctrl *ctrl, char **path)
{
  t_file	*new_file;
  char		*temp;

  new_file = NULL;
  while (*path != NULL)
    {
      printf("****LOOP****\n");
      if ((temp = my_strdup(*path)) == FALSE)
	return (FALSE);
      if (check_ext(INEXT, temp, &new_file) == FALSE)
	{
	  free(temp);
	  return (FALSE);
	}
      free(temp);
      if (open_io(new_file, ctrl) == FALSE)
	return (FALSE);
      path++;
    }
  return (TRUE);
}
