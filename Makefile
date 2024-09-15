NAME = push_swap
NAME_BONUS = checker

#########
RM = rm -f
CC = cc
CFLAGS = -Werror -Wextra -Wall
#########

#########
FILES = algorithm arg_check error fill_a push push_swap reverse_rotate rotate small_cases swap

FILES_BONUS = arg_check_bonus checker_bonus error_bonus fill_a_bonus get_next_line_bonus get_next_line_utils_bonus push_bonus reverse_rotate_bonus rotate_bonus swap_bonus

SRC = $(addsuffix .c, $(FILES))

SRC_BONUS = $(addsuffix .c, $(FILES_BONUS))

vpath %.c srcs srcs_bonus
#########

#########
OBJ_DIR = objs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))
DEP_BONUS = $(addsuffix .d, $(basename $(OBJ_BONUS)))
#########

#########
$(OBJ_DIR)/%.o: %.c	
	@mkdir -p $(@D)
	@${CC} $(CFLAGS) -MMD -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "EVERYTHING DONE   "

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

bonus:
	@$(MAKE) $(NAME_BONUS) 

clean:
	$(RM) $(OBJ) $(DEP) $(OBJ_BONUS) $(DEP_BONUS)
	$(RM) -r $(OBJ_DIR) 
	@echo "OBJECTS REMOVED   "

fclean: clean	
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "EVERYTHING REMOVED   "

re:	fclean all

.PHONY: all clean fclean re bonus

-include $(DEP)
-include $(DEP_BONUS)

#########
