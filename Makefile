MAIN		= push_swap
CHECKER		= checker

CC			= gcc -g
CFLAGS		= -Wall -Wextra

SRCS		= src/main.c \
			  src/rules.c \
			  src/sort.c \
			  src/utils.c \
			  src/error.c \
			  src/ft_lstnew.c \
			  src/ft_lstadd_front.c \
			  src/ft_lstadd_back.c \
			  src/ft_lstsize.c \
			  src/ft_lstlast.c \
			  src/ft_lstclear.c \

BONUS		= src/checker.c \
			  src/get_next_line.c \

INC			= -I./include -I./libft -I./printf
LIBFT		= -Llibft -lft 
PRINTF		= -Lprintf -lftprintf

OBJ			= $(SRCS:src/%.c=obj/%.o)
OBJ_BONUS	= $(BONUS:src/%.c=obj/%.o)

obj/%.o: src/%.c create_obj_dir
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: create_obj_dir $(MAIN) 

create_obj_dir :
	@mkdir -p obj

make_libs:
	@echo ✅ "Compile libft\n"
	@make re -s -C ./libft
	@echo ✅ "Compile ft_printf\n"
	@make re -s -C ./printf

$(MAIN): $(OBJ)
	@echo ✅ "Compile push_swap\n"
	@$(CC) $^ -o $@ $(INC) $(LIBFT) $(PRINTF)

bonus:	$(OBJ_BONUS)
	@echo ✅ "Compile checker\n"
	@$(CC) $^ -o checker $(INC) $(LIBFT) $(PRINTF)
 

clean_libs:
	@echo ✅ "Clean libft\n"
	@make fclean -s -C ./libft
	@echo ✅ "Clean ft_printf\n"
	@make fclean -s -C ./printf
	
clean: 
	@echo ✅ "Clean push_swap\n"
	@rm -rf $(OBJ)
	@rm -rf obj/

fclean: clean
	@rm -f $(MAIN)

re: fclean all

.PHONY: all clean fclean re \
	create_directory \
	clean_lib \

