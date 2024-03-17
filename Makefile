NAME = push_swap
BNAME = checker
SRC = ./mandatory/push_swap.c\
./mandatory/push_swap_utils.c\
./mandatory/sort_it.c\
./mandatory/best_move.c\
./mandatory/best_move_utils.c\
./mandatory/chunks.c\
./mandatory/operations.c\
./mandatory/operations_2.c\
./mandatory/free_mem.c
OBJ =  ${SRC:.c=.o}
BSRC = ./bonus/push_swap_bonus.c\
./bonus/push_swap_utils_bonus.c\
./bonus/operations_bonus.c\
./bonus/operations_2_bonus.c\
./bonus/apply_fun_bonus.c\
./bonus/get_next_line_bonus.c\
./bonus/get_next_line_utils_bonus.c
BOBJ = ${BSRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LIB = ./mandatory/push_swap.h
BLIB = ./bonus/get_next_line_bonus.h ./bonus/push_swap_bonus.h
LIBS = ./libft/libft.a ./ft_printf/libftprintf.a
all : ${NAME}

${NAME} : ${OBJ}
	make -C ./libft
	make -C ./ft_printf
	${CC} ${CFLAGS} ${OBJ} ${LIBS} -o $@
bonus: ${BNAME}

${BNAME} : ${BOBJ}
	make -C ./libft
	make -C ./ft_printf
	${CC} ${CFLAGS} ${BOBJ} ${LIBS} -o $@
${BOBJ} : ${BLIB}
%.o : %.c ${LIB}
	${CC} ${CFLAGS} -c -o $@ $<
clean:
	rm -f ${OBJ} ${BOBJ}
	make -C ./libft clean
	make -C ./ft_printf clean
fclean: clean
	rm -f ${NAME} ${BNAME}
	make -C ./libft fclean
	make -C ./ft_printf fclean
re: fclean all
.PHONY : clean