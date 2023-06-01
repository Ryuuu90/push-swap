NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Werror -Wextra 

SRCS =	get_next_line.c\
		get_next_line_utils.c\

OBJS = ${SRCS:.c=.o}

ARV = ar -rc

REM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@$(ARV) $(NAME) $(OBJS)
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@${REM} ${OBJS}

fclean : clean
	@${REM} ${NAME}

re : fclean all

.PHONY: clean fclean all re
