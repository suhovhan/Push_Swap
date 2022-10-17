NAME = push_swap

# BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

# OBJ_BONUS_DIR = obj_bonus

SRCS = $(wildcard ./src/*.c)

# SRCS_BONUS = $(wildcard ./bonus/*.c)

OBJS = $(patsubst ./src/%.c, ./$(OBJ_DIR)/%.o, $(SRCS))

# OBJS_BONUS = $(patsubst ./bonus/%.c, ./$(OBJS_BONUS_DIR)/%.o, $(SRCS_BONUS))

MK = mkdir -p

RM = rm -f

RMRF = rm -rf

LIBCACH = ~/Library/Caches/

$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_BONUS_DIR)/%.o: ./bonus/%.c | $(OBJ_BONUS_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# bonus: $(NAME) $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# $(BONUS): $(OBJS_BONUS)
# 	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS)

$(OBJ_DIR):
	$(MK) -p $(OBJ_DIR)

# $(OBJ_BONUS_DIR):
# 	$(MK) -p $(OBJ_BONUS_DIR)

clean:
	$(RMRF)	$(OBJ_DIR)
	# $(RMRF)	$(OBJ_BONUS_DIR)

fclean: clean
	$(RM)  $(NAME)
	# $(RM)  $(BONUS)
	$(RMRF) $(LIBCACH)

re: fclean all

.PHONY: all clean fclean re