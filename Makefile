NAME = push_swap

BONUS = checker

SRC =	push_swap.c\
		parse.c\
		sort/lst_funs.c\
		sort/moves_a.c\
		sort/moves_b.c\
		sort/sort.c\
		sort/quick_sort.c\
		sort/utils.c\
		sort/moves.c\

SRC_BONUS = bonus/checker.c\
			bonus/moves_a_bonus.c\
			bonus/moves_b_bonus.c\
			bonus/parse_b.c\
			bonus/moves_bonus.c\
			sort/lst_funs.c\
		
RM = rm -rf
all: $(NAME)

$(NAME): $(SRC)
	@cd libft && make all
	@cc -Wall -Wextra -Werror $(SRC) libft/libft.a -o $(NAME)
	@echo "\033[1;32mPush_swap is ready to execute ✅\033[0m"
	
bonus: $(BONUS)

$(BONUS): $(SRC_BONUS)
	@cd libft && make all
	@cd get_next_line && make all
	@cc -Wall -Wextra -Werror $(SRC_BONUS) libft/libft.a get_next_line/get_next_line.a -o $(BONUS)
	@echo "\033[1;32mChecker is ready to execute ✅\033[0m"


clean:
	@cd libft && make clean
	@cd get_next_line && make clean
	@echo "\033[1;31mObject files deleted successfully 🗑\033[0m"

fclean: clean
	@cd libft && make fclean
	@cd get_next_line && make fclean
	@$(RM) push_swap
	@$(RM) checker
	@echo "\033[1;31mExecution file deleted successfully 🗑\033[0m"

re: fclean all

git :
	git add . && git commit -m "hbh" && git push origin main

.PHONY: clean fclean all re bonus