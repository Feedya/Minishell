NAME = minishell
DEBUG = minishell_debug

#VALGRIND :valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp ./minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
READ_FLAGS = -lreadline

#-------------------------------------------------------
# CHEMIN/PATH : CHEMIN/PATH : CHEMIN/PATH : CHEMIN/PATH DE DOSSIER
# DOSSIER : DOSSIER : DOSSIER : DOSSIER : DOSSIER : DOSSIER
STDIN_STDOUT_DIR = src/stick_stdin_stdout
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
EXECUTION_SRC = src/execution
EXECUTE_EXTERN_DIR = src/execution/EXTERN
ARGC_OF_COMMAND_DIR = src/verification_du_parsing/create_argc_of_command
ENV_VARIABLES_DIR = src/verification_du_parsing/expand_env_variables
EXPAND_ENV_VARIABLES = src/verification_du_parsing/expand_env_variables
REDERICTION_DIR = src/stick_stdin_stdout/make_redirictions
#build in
BUILDIN_DIR = src/execution/BUILD_IN
MAKE_CD_DIR = src/execution/BUILD_IN/make_cd
#export dir
MAKE_EXPORT_DIR = src/execution/BUILD_IN/make_export
#unset dir
MAKE_UNSET_DIR = src/execution/BUILD_IN/make_unset
#-----------------------------------------------------------

#-----------------------------------------------------------
#FICHIER : FICHIER : FICHIER : FICHIER : FICHIER : FICHIER

#Execution
EXECUTION_DIR = $(EXECUTION_SRC)/execution.c $(EXECUTION_SRC)/make_dup.c

#make cd
MAKECD_DIR = $(MAKE_CD_DIR)/make_cd.c $(MAKE_CD_DIR)/make_cd_home.c $(MAKE_CD_DIR)/make_cd_utils.c

#make unset
MAKEUNSET_DIR = $(MAKE_UNSET_DIR)/make_unset.c

#make export
MAKEEXPORT_DIR = $(MAKE_EXPORT_DIR)/make_export.c $(MAKE_EXPORT_DIR)/print_all_export.c\
		$(MAKE_EXPORT_DIR)/add_to_env.c $(MAKE_EXPORT_DIR)/add_to_export.c\
		$(MAKE_EXPORT_DIR)/add_to_value_env.c

#build in
BUILDIN_SRC = $(BUILDIN_DIR)/make_echo.c $(BUILDIN_DIR)/make_build_in_command.c $(BUILDIN_DIR)/make_pwd.c $(BUILDIN_DIR)/make_env.c

EXTERNEXTERN_DIR = $(EXECUTE_EXTERN_DIR)/execute_child_extern.c $(EXECUTE_EXTERN_DIR)/make_extern_command.c

VERIFICATION_SRC = $(VERIFICATION_DIR)/put_files.c\
		$(VERIFICATION_DIR)/verifier_commande.c $(VERIFICATION_DIR)/verification_du_parsing.c\
		$(VERIFICATION_DIR)/remove_empty_double_and_single_quotes.c $(VERIFICATION_DIR)/remove_quotes_from_commande.c\
		$(VERIFICATION_DIR)/verifier_pipe.c

PARSING_SRCS = $(PARSING_DIR)/add_double_quotes.c\
		$(PARSING_DIR)/add_commande.c $(PARSING_DIR)/parsing.c\
		$(PARSING_DIR)/add_single_quotes.c\
		$(PARSING_DIR)/add_redirect_in_out.c $(PARSING_DIR)/add_append_heredoc.c\
		$(PARSING_DIR)/add_pipe.c\
		$(PARSING_DIR)/add_word.c

UTILS_SRC = $(UTILS_DIR)/utils_liste.c $(UTILS_DIR)/utils.c $(UTILS_DIR)/utils_all.c $(UTILS_DIR)/utils_shell_cmd.c

ARGCOFCOMMAND_DIR = $(ARGC_OF_COMMAND_DIR)/create_argc_of_command.c $(ARGC_OF_COMMAND_DIR)/remplir_argc_of_command.c

FILLFLAGCOMMANDENODE_DIR = $(FILL_FLAG_COMMANDE_NODE_DIR)/fill_flag_and_commande.c $(FILL_FLAG_COMMANDE_NODE_DIR)/create_char_commande_node.c

ENVVARIABLES_DIR = $(ENV_VARIABLES_DIR)/put_env_variables.c $(ENV_VARIABLES_DIR)/fill_expanded_str.c $(ENV_VARIABLES_DIR)/count_taille_str_with_env.c

ENVALL_DIR =	$(ENV_ALL_DIR)/copy_env_of_all.c $(ENV_ALL_DIR)/create_env_of_all.c $(ENV_ALL_DIR)/malloc_fill_env_values.c

STDIN_STDOUT = $(STDIN_STDOUT_DIR)/stick_stdin_stdout.c $(STDIN_STDOUT_DIR)/make_pipe.c\
		$(STDIN_STDOUT_DIR)/make_by_default.c

#EXPANDENVVARIABLES_DIR = $(EXPAND_ENV_VARIABLES)/expand_env_variables.c
MAKEREDERICTION_DIR = $(REDERICTION_DIR)/make_redirictions.c\
		$(REDERICTION_DIR)/make_redirect_out.c $(REDERICTION_DIR)/make_redirect_in.c\
		$(REDERICTION_DIR)/make_redirect_heredoc.c $(REDERICTION_DIR)/make_redirect_append.c\
#------------------------------------------------------------------


#------------------------------------------------
# SOURCES : SOURCES : SOURCES : SOURCES :
SRCS = $(SRC_DIR)/main.c \
		$(SIGNAL_DIR)/make_signal.c\
		$(PATH_DIR)/copy_path.c\
		$(PARSING_SRCS) $(UTILS_SRC) $(VERIFICATION_SRC) $(ARGCOFCOMMAND_DIR)\
		$(FILLFLAGCOMMANDENODE_DIR) $(ENVALL_DIR)\
		$(STDIN_STDOUT) $(MAKEREDERICTION_DIR)\
		$(EXTERNEXTERN_DIR) $(EXECUTION_DIR)\
		$(BUILDIN_SRC) $(ENVVARIABLES_DIR)\
		$(MAKECD_DIR) $(MAKEEXPORT_DIR)\
		$(MAKEUNSET_DIR)
#-------------------------------------------------
#$(EXPANDENVVARIABLES_DIR)



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