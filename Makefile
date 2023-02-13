NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc
OBJ_DIR = obj
OBJ_BONUS_DIR = objbonus
SRCS = $(wildcard src/*.c)
SRCS_BONUS = $(wildcard bonus/*.c)
OBJS = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS_MAIN = $(wildcard $(OBJ_DIR)/main.o)
OBJS_OTHER = $(filter-out $(OBJS_MAIN), $(OBJS))
OBJS_BONUS = $(patsubst bonus/%.c, $(OBJ_BONUS_DIR)/%.o, $(SRCS_BONUS))
MK = mkdir
RM = rm -f
RMRF = rm -rf
LIBCACH = ~/Library/Caches/

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_YELLOW=\033[0;33m
COLOUR_NEW=\033[0;36m
COLOUR_END=\033[0m

$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: ./bonus/%.c | $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(BONUS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(COLOUR_GREEN)COMPILED😍$(COLOUR_END)"

$(BONUS): $(OBJS_BONUS) 
		@# @$(RM) $(OBJS_MAIN)
		@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(OBJS_OTHER)
		@echo "$(COLOUR_YELLOW)COMPILED BONUS😜$(COLOUR_END)"

$(OBJ_DIR):
	@$(MK) -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@$(MK) -p $(OBJ_BONUS_DIR)

clean:
	@$(RMRF)	$(OBJ_DIR)
	@$(RMRF) $(OBJ_BONUS_DIR)
	@echo "$(COLOUR_RED)CLEANED🤨$(COLOUR_END)"

fclean: clean
	@$(RM)  $(NAME)
	@$(RM)  $(BONUS)
	@$(RMRF) $(LIBCACH)
	@echo "$(COLOUR_NEW)THANK YOU😘$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
