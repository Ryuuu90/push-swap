SRC =	push_swap.c\
		parce.c\
		lst_funs.c\
		moves_a.c\
		moves_b.c\
		sort.c\
		quick_sort.c\
		
RM = rm -rf
all: push_swap

push_swap: $(SRC)
	@cd libft && make all
	@cc $(SRC) libft/libft.a -o push_swap


clean:
	@cd libft && make clean

fclean: clean
	@cd libft && make fclean
	@$(RM) push_swap

re: fclean all

git :
	git add . && git commit -m "hbh" && git push origin main

.PHONY: clean fclean all re