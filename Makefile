##
## Makefile for explora in /home/keolas_s//test/systeme_unix/explora
## 
## Made by souvisay keolasy
## Login   <keolas_s@epitech.net>
## 
## Started on  Tue Oct 15 08:44:43 2013 souvisay keolasy
## Last update Thu Nov 28 15:07:17 2013 souvisay keolasy
##

SRCSDIR	= sources
INCSDIR	= includes
BINSDIR	= bins
BONUDIR	= bonus

NAME	= $(BINSDIR)/korewar
NAMEP1	= $(BINSDIR)/korewar

SRCS	= $(SRCSDIR)/main.c \
	  $(SRCSDIR)/op.c \
	  $(SRCSDIR)/open_file.c \
	  $(SRCSDIR)/read_header.c \
	  $(SRCSDIR)/read_file.c \
	  $(SRCSDIR)/endian.c

OBJS	= $(SRCS:.c=.o)


LIB	= tools

CFLAGS	= -Wall -Wextra -ansi -std=c89 -pedantic
CFLAGS	+= -I $(INCSDIR)
LDFLAGS	+= -ltools -L ./tools -lncurses

DEBUG	= false

ifeq	($(DEBUG), true)
	CFLAGS	+= -ggdb3
	CC	= clang
else
	CC	= gcc
	CLFAGS	+= -O2
endif

RM	= rm -fr

all: $(NAME)

%.o: %.c
	@ echo	"  CC		$<"
	@ $(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	@ echo	"  BIN		$(NAME)"
	@ $(CC) -o $(NAME) $(OBJS)  $(LDFLAGS)

lib:
	@ make re -C $(LIB)

clean:
	@ echo	"  RM		$(OBJS)"
	@ $(RM) $(OBJS)

fclean:	clean
	@ echo	"  RM		$(NAME)"
	@ $(RM) $(NAME)

re:	fclean	lib	all

.PHONY: clean	fclean	lib all
