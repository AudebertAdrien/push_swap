MAIN		= push_swap
CHECKER		= checker

CC			= gcc -g
CFLAGS		= -Wall -Wextra

VPATH		= src

SRCS		= main.c \

BONUS		= checker.c \
			  get_next_line.c \

UTILS		= rules.c \
			  sort.c \
			  utils.c \
			  error.c \
			  ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstadd_back.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstclear.c \

INC			= -I./include -I./libft -I./printf
LIBFT		= -Llibft -lft 
PRINTF		= -Lprintf -lftprintf

OBJ			= $(addprefix obj/, $(SRCS:.c=.o) $(UTILS:.c=.o))
OBJ_BONUS	= $(addprefix obj/, $(BONUS:.c=.o) $(UTILS:.c=.o))

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
	@$(CC) $^ -o $(CHECKER) $(INC) $(LIBFT) $(PRINTF)
 

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

