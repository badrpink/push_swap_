NAME = libftprintf.a
CC = cc
Cflags = -Wall -Wextra -Werror
SRC = ft_printf.c\
	  ft_putstr_fd.c\
	  ft_strlen.c \
	  ft_toupper.c
OBJ = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	ar rc $@ $^

%.o : %.c ft_printf.h
	${CC} ${Cflags} -c -o $@ $<

clean :
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all
