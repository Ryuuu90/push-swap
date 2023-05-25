NAME = libftft_printf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_lowerhexa.c \
		ft_upperhexa.c \
		ft_printads.c \
		ft_lowerhexa_p.c \
		ft_putnbr_un.c \

OBJS = ${SRCS:.c=.o}

ARV = ar -rc

REM = rm -f

all : ${NAME}

${NAME} : ${OBJS}
	@${ARV} ${NAME} ${OBJS}
%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@
clean : 
	@${REM} ${OBJS}
fclean : clean
	@${REM} ${NAME}
re : fclean all

.PHONY : clean fclean all re