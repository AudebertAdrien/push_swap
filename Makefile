NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra

SRCS		= src/main.c \

INC			= -I./include -I./libft -I./printf

OBJ			= $(SRCS:src/%.c=obj/%.o)

obj/%.o: src/%.c create_obj_dir
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: create_obj_dir $(NAME) 

make_lib:
	@echo ✅ "Compile libft\n"
	@make re -s -C ./libft
	@echo ✅ "Compile ft_printf\n"
	@make re -s -C ./printf

create_obj_dir :
	@mkdir -p obj

$(NAME): $(OBJ)
	@echo ✅ "Compile push_swap\n"
	@$(CC) $^ -o $@ $(INC) -Llibft -lft -Lprintf -lftprintf

clean_lib:
	@echo ✅ "Clean libft\n"
	@make fclean -s -C ./libft
	@echo ✅ "Clean ft_printf\n"
	@make fclean -s -C ./printf
	
clean:
	@echo ✅ "Clean push_swap\n"
	@rm -rf $(OBJ)
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re \
	create_directory \
	clean_lib \

