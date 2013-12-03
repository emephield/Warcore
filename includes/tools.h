/*
** tools.h for magic21 in /home/keolas_s//test/prog_elem/magic21
** 
** Made by souvisay keolasy
** Login   <keolas_s@epitech.net>
** 
** Started on  Wed Sep 25 09:02:18 2013 souvisay keolasy
** Last update Thu Nov 28 09:35:38 2013 souvisay keolasy
*/

#ifndef		TOOLS_H_
# define	TOOLS_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define	FD_EOF		0
# define	SIGNED		0
# define	UNSIGNED	1
# define	UNUSED(x)	((void) x)
# define	MY_SWAP(a, b)	{a ^= b ^= a ^= b;}

void    my_putchar(char c);
void    my_putnbr(unsigned int nb);
void	my_putstr(const char *str);
void	my_bzero(void *ptr, const int len);
int	my_strlen(const char *str);
void	*my_memset(void *s, char c, int n);
int	my_getnbr(char *nbr, int type);
int	my_strcmp(char *s1, char *s2);
void	*my_malloc(int size);
char	*my_strdup(char *str);
char	*my_strndup(char *str, int len);
int	my_strncmp(char *s1, char *s2, int size);
char	*my_revstr(char *str);
char	*my_revmem(char *str, int len);
char	*my_stradd(char *s1, char *s2);

int	my_read(const int fd, void *buf, const int count);
int	my_close(int fd);
int	my_create(char *path, int flags, int mode);
int	my_open(char *path, int flags);

#endif		/* TOOLS_H_ */
