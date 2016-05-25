FLAGS	= -Wall -Wextra -Werror -g
CC		= gcc $(FLAGS)
INCS 	= -I./incs -I./libft/includes
LIBS 	= ./libft
LANGAGE	= c

NAME	= lem-in

SRC_DIR = srcs
OBJ_DIR = objs

LIST 	= ft_lemin \
ft_lemin_error \
ft_lemin_prun \
ft_lemin_free \
ft_lemin_addlink \
ft_lemin_roads \
ft_lemin_addbox

SRC := $(addprefix $(SRC_DIR)/, $(addsuffix .$(LANGAGE), $(LIST)))
OBJ := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIST)))

C_END	= "\033[0m"
C_GOOD	= "\033[32m"
C_GREY  = "\033[1;30m"
C_BAD	= "\033[31m"
C_BLUE	= "\033[34;1m"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBS)
	$(CC) $(OBJ) -o $@ -L$(LIBS) -lft
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(LANGAGE)
	@mkdir -p $(dir $@)
	$(CC) $(INCS) -o $@ -c $<

test: $(NAME)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] start"
	@./$(NAME) < ./maps/basic.map

clean:
	@make clean -C $(LIBS)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

clean2:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

fclean: clean2
	@make fclean -C $(LIBS)
	@/bin/rm -f $(NAME)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] bin deleted"

leaks: $(NAME) -leaks
#leaks: test

-leaks:
	@-valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) < maps/test9

re: fclean libft $(NAME)

.PHONY: all clean clean2 fclean re libft test
