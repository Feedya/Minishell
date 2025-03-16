NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
READ_FLAGS = -lreadline

OBJ_DIR = obj
SRC_DIR = src
PATH_DIR = src/PATH
ENV_ALL_DIR = src/env_all
SIGNAL_DIR = src/signal
PARSING_DIR = src/parsing

SRCS = $(SRC_DIR)/main.c \
			$(ENV_ALL_DIR)/copy_env_of_all.c $(SRC_DIR)/utils.c\
		$(ENV_ALL_DIR)/create_env_of_all.c $(SIGNAL_DIR)/make_signal.c\
		$(PATH_DIR)/copy_path.c \
		$(PARSING_DIR)/add_commande.c $(PARSING_DIR)/parsing.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(READ_FLAGS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re leak