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
VERIFICATION_DIR = src/verification_du_parsing
UTILS_DIR = src/utils

SRCS = $(SRC_DIR)/main.c \
			$(ENV_ALL_DIR)/copy_env_of_all.c\
		$(ENV_ALL_DIR)/create_env_of_all.c $(SIGNAL_DIR)/make_signal.c\
		$(PATH_DIR)/copy_path.c $(PARSING_DIR)/add_double_quotes.c\
		$(PARSING_DIR)/add_commande.c $(PARSING_DIR)/parsing.c\
		$(PARSING_DIR)/add_single_quotes.c\
		$(PARSING_DIR)/add_redirect_in_out.c $(PARSING_DIR)/add_append_heredoc.c\
		$(PARSING_DIR)/add_pipe.c $(PARSING_DIR)/add_first_commande.c\
		$(PARSING_DIR)/add_word.c $(VERIFICATION_DIR)/verification_du_parsing.c\
		$(VERIFICATION_DIR)/put_files.c\
		$(UTILS_DIR)/utils_liste.c $(UTILS_DIR)/utils.c $(VERIFICATION_DIR)/remove_empty_double_and_single_quotes.c\
		$(VERIFICATION_DIR)/verifier_commande.c

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