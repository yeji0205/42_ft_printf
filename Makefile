SRCS = ft_printf.c ft_write_num.c ft_write_word.c \

#B_SRCS = 

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = cc

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all:	${NAME}

#bonus: ${B_OBJS}
#	@ar rcs ${NAME} ${B_OBJS}

clean:
	rm -f ${OBJS}
	rm test
#	rm -f ${B_OBJS}

fclean: clean
	rm -f ${NAME} 

re: fclean all

test:
	${CC} -o test ${SRCS} ${CFLAGS}


.PHONY: all clean fclean re