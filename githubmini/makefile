NAME = minishell
DEBUG = minishell_debug

#VALGRIND :valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp ./minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
READ_FLAGS = -lreadline

OBJ_DIR = obj
PARSING_DIR = src/parsing
SRC_DIR = src
PATH_DIR = src/PATH
ENV_ALL_DIR = src/env_all
SIGNAL_DIR = src/signal
PARSING_COMMANDE_DIR = src/parsing/add_commande
VERIFICATION_DIR = src/verification_du_parsing
UTILS_DIR = src/utils
FILL_FLAG_COMMANDE_NODE_DIR = src/verification_du_parsing/fill_flag_and_commande
#EXECUTION_DIR = src/execution
ARGC_OF_COMMAND_DIR = src/verification_du_parsing/create_argc_of_command
ENV_VARIABLES_DOUBLE_DIR = src/verification_du_parsing/put_env_variables
ENV_VARIABLES_SINGLE_DIR = src/verification_du_parsing/put_env_variables_in_single_quotes

VERIFICATION_SRC = $(VERIFICATION_DIR)/put_files.c\
		$(VERIFICATION_DIR)/verifier_commande.c $(VERIFICATION_DIR)/verification_du_parsing.c\
		$(VERIFICATION_DIR)/remove_empty_double_and_single_quotes.c $(VERIFICATION_DIR)/remove_quotes_from_commande.c\
		$(VERIFICATION_DIR)/verifier_pipe.c $(VERIFICATION_DIR)/verification_rederictions.c

PARSING_SRCS = $(PARSING_DIR)/add_double_quotes.c\
		$(PARSING_DIR)/add_commande.c $(PARSING_DIR)/parsing.c\
		$(PARSING_DIR)/add_single_quotes.c\
		$(PARSING_DIR)/add_redirect_in_out.c $(PARSING_DIR)/add_append_heredoc.c\
		$(PARSING_DIR)/add_pipe.c\
		$(PARSING_DIR)/add_word.c $(PARSING_DIR)/add_first_arg.c

UTILS_SRC = $(UTILS_DIR)/utils_liste.c $(UTILS_DIR)/utils.c $(UTILS_DIR)/utils_all.c

ARGCOFCOMMAND_DIR = $(ARGC_OF_COMMAND_DIR)/create_argc_of_command.c $(ARGC_OF_COMMAND_DIR)/remplir_argc_of_command.c\

FILLFLAGCOMMANDENODE_DIR = $(FILL_FLAG_COMMANDE_NODE_DIR)/fill_flag_and_commande.c $(FILL_FLAG_COMMANDE_NODE_DIR)/create_char_commande_node.c\

ENVVARIABLESDOUBLE_DIR = $(ENV_VARIABLES_DOUBLE_DIR)/put_env_variables.c $(ENV_VARIABLES_DOUBLE_DIR)/count_taille_str_with_env.c $(ENV_VARIABLES_DOUBLE_DIR)/fill_expanded_str.c

#ENVVARIABLESSINGLE_DIR = $(ENV_VARIABLES_SINGLE_DIR)/put_env_variables_in_single_quotes.c

ENVALL_DIR =	$(ENV_ALL_DIR)/copy_env_of_all.c $(ENV_ALL_DIR)/create_env_of_all.c $(ENV_ALL_DIR)/malloc_fill_env_values.c\

SRCS = $(SRC_DIR)/main.c \
		$(SIGNAL_DIR)/make_signal.c\
		$(PATH_DIR)/copy_path.c\
		$(PARSING_SRCS) $(UTILS_SRC) $(VERIFICATION_SRC) $(ARGCOFCOMMAND_DIR)\
		$(FILLFLAGCOMMANDENODE_DIR) $(ENVVARIABLESDOUBLE_DIR) $(ENVALL_DIR)\


OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

debug: $(NAME)
	@echo "Compile with debug..."
	@$(CC) $(CFLAGS) -g -o $(DEBUG) $(OBJS) $(READ_FLAGS)

$(NAME): $(OBJS)
	@printf "\nCompilation Executable\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(READ_FLAGS)
	@printf "Done\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@printf "Compiling: %s                                                       \r" $@
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re leak