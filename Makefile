SRCS = ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c \
       ft_putunbr.c ft_puthex.c ft_percent.c ft_printf.c
SRCSB = ft_test_bonus.c
OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

bonus: ${NAME} ${OBJSB}
	ar rcs ${NAME} ${OBJSB}

test: ${NAME}
	$(CC) $(CFLAGS) -o test ${NAME}

clean:
	rm -f ${OBJS} ${OBJSB}

fclean: clean
	rm -f ${NAME} ${bonus} 

re: fclean all

.PHONY : all bonus clean fclean re