NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

SRCS = $(wildcard ./src/*.c)

OBJS = $(patsubst ./src/%.c, ./$(OBJ_DIR)/%.o, $(SRCS))

MK = mkdir -p

RM = rm -f

RMDIR = rm -rf

$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR):
	$(MK) -p $(OBJ_DIR)

clean:
	$(RMDIR)	$(OBJ_DIR)

fclean: clean
	$(RM)  $(NAME)

re: fclean all

.PHONY: all clean fclean re