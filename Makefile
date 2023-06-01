NAME = push_swap

SRC =	push_swap.c\
		parce.c\
		sort/lst_funs.c\
		sort/moves_a.c\
		sort/moves_b.c\
		sort/sort.c\
		sort/quick_sort.c\
		sort/utils.c\
		sort/moves.c\
		sort/print_moves.c\

SRC_BONUS = bonus/checker.c\
			bonus/moves_a_bonus.c\
			bonus/moves_b_bonus.c\
			bonus/parce_b.c\
			sort/lst_funs.c\
		
RM = rm -rf
all: $(NAME) clean

$(NAME): $(SRC)
	@cd libft && make all
	@cc -Wall -Wextra -Werror $(SRC) libft/libft.a -o $(NAME)
bonus : $(SRC_BONUS)
	@cd libft && make all
	@cd get_next_line && make all
	@cc -Wall -Wextra -Werror $(SRC_BONUS) libft/libft.a get_next_line/get_next_line.a -o checker


clean:
	@cd libft && make clean
	@cd get_next_line && make clean

fclean: clean
	@cd libft && make fclean
	@cd get_next_line && make fclean
	@$(RM) push_swap
	@$(RM) checker

re: fclean all

git :
	git add . && git commit -m "hbh" && git push origin main

.PHONY: clean fclean all re bonus