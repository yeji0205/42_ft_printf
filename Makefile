SRCS = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \

#B_SRCS = 

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = cc

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all:	${NAME}

#bonus: ${B_OBJS}
#	@ar rcs ${NAME} ${B_OBJS}

clean:
	rm -f ${OBJS}
#	rm -f ${B_OBJS}

fclean: clean
	rm -f ${NAME} 

re: fclean all


.PHONY: all clean fclean re