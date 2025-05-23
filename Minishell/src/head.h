#ifndef HEAD_H
# define HEAD_H
//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt
//valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./minishell

//TRUQUE IMPORTANT
//
//1 : Chaque fois que j ai une fonciton qui renvoie un int pour dire si c est juste ou faux : 1 est pour faux et 0 est pour juste

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <stddef.h>
#include <term.h>
#include <fcntl.h>

#define	HOME_VALUE	"HOME=/home/fepopadi"
#define PATH_VALUE	"PATH=/home/fepopadi/bin:/home/fepopadi/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
#define PWD_VALUE		"PWD=/home/fepopadi/Desktop/Minishell"
#define	USER_VALUE	"USER=fepopadi"
#define	SHLVL_VALUE	"SHLVL=1"

typedef struct t_line t_line;
typedef struct t_shell_command t_shell_command;

//dans execution pour vite voir quelle commande c est
typedef enum build_in_type
{
  NONE_FUNCT,
  ECHO_BUILD_IN,
  CD_BUILD_IN,
  PWD_BUILD_IN,
  EXPORT_BUILD_IN,
  UNSET_BUILD_IN,
  ENV_BUILD_IN,
  EXIT_BUILD_IN,
} e_build_in_type;

typedef enum token_type //le type de chaque charactere qu on regarde
{
  TOKEN_SINGLE_QUOTES, //0' '
  TOKEN_DOUBLE_QUOTES, //1 ""
  TOKEN_PIPE, //2 |
  TOKEN_REDIRECT_IN, //3 <
  TOKEN_REDIRECT_OUT, //4 >
  TOKEN_APPEND, //5 >>
  TOKEN_HEREDOC, //6 <<
  TOKEN_COMMANDE, //7 commande
  TOKEN_WORD, //8 MOT NORMALE SANS QUOTES
  TOKEN_FILES, //9 FICHIER APRES < >
} e_token_type;

typedef enum quotes // pour savoir si le charactere qu on regarde si il est dans des double single ou pas de quotes
{
  DOUBLE_QUOTES,
  SINGLE_QUOTES,
  NONE,
} e_quotes;

typedef enum command_type
{
  BUILD_IN,
  EXTERN,
  PAS_COMMANDE,
} e_command_type;

typedef struct t_line
{
  int index; // que pour commande c est l index dans les variables d env
  struct t_line *next;
  struct t_line *prev;
  char *valeur; //tout
  char *commande_path;//que si commande
  char *commande; // on utilise que si commande
  char *flag; // utilise que si commande
  char **argc;
  e_token_type type;//type
  e_quotes quotes;
  e_build_in_type build_in_type;
  e_command_type command_type; // utiliser que commande
  t_shell_command *fd; // que commande
} t_line;

typedef struct t_all
{
  //int start; // index pour les double quotes ou ils commencent et ou ils finissent le int end aussi
  //int end;
  int commande; //parsing//sera a 1 si on a une commande donc on cerche un argument ou redericition 0 si on a pas de commande avant
  char *line;
  char **path;
  char **path_values;
  char **env;
  char **export;
} t_all;

//pour execution liste de coommandes shell
typedef struct t_shell_command
{
  struct t_shell_command	*next;
  struct t_shell_command	*prev;
	int	error_indicator; //message d erreur
	int	stdin;
	int	stdout;
	t_line	*command_info;// pointeur sur commande
}	t_shell_command;

//MAIN
int	main(int argc, char **argv, char **env);

//UTILS
int	ft_strlen(char *str);
void	ft_strcpy(char *str, char *dest);
int	ft_strncmp(char *avec_quoi, char *comparer, int nbr);
void	ft_strncpy(char *str, char *dest, int index, int taille);
void	ft_strcat(char *dest, char *str);
int	ft_comparer(char *str, char *str2);
char	*create_string(char *str);

//UTILS LISTE
void	add_node_to_head(t_line **head, t_line *node);
void	print_list(t_line **head);
void	printf_liste_a_lenvers(t_line **head);
t_all	*malloc_struct_all(void);
void	free_list(t_line **head);


//UTILS ALL
void	free_all(t_all *all);
void  print_env(t_all *all);
void	print_char_export(char **export);
void	free_double_char(char **map);
void	print_double_char(char **map);

//UTILS SHELL COMMAND
void  free_shell_cmd(t_shell_command **head);
t_shell_command ** malloc_head_shell_cmd(void);
t_shell_command	*create_shell_cmd_node(void);
void  put_node_to_liste_shell_cmd(t_shell_command **head, t_shell_command *node);

//ENV_ALL
void  create_env_in_all(t_all *all);
void	malloc_env_values(t_all *all, char **env, int big_size);
void	copy_env_in_all(t_all *all, char **env);
void  create_env_in_all(t_all *all);
void	find_index_env_values(char *env, int *index);

// PATH
void  copy_path(t_all *all);

// SIGNAL
void  make_signal(void);


//PARSING
void  parsing(t_all *all, t_line **head);
//ADD DOUBLE QUOTES
void	add_double_quotes(t_all *all, t_line **head, int *index);
//ADD SINGLE QUOTES
void	add_single_quotes(t_all *all, t_line **head, int *index);
//ADD COMMANDE
void	add_commande(int *index, t_all *all, t_line **head);
//ADD IN AND OUT
void  add_redirect_in_out(t_all *all, t_line **head, int *index);
//ADD HEREDOC APPEND
void  add_append_heredoc(t_all *all, t_line **head, int *index);
//ADD PIPE
void  add_pipe(t_all *all, t_line **head, int *index);
//ADD COMMANDE
void	add_commande(int *index, t_all *all, t_line **head);
//ADD FIRST COMMANDE
void	add_first_commande(int *index, t_all *all, t_line **head);
//ADD WORD
void  add_word(t_all *all, t_line **head, int *index);


//VERIFICATION DU PARSIN
void  verification_du_parsing(t_line **head, t_all *all);
//PUT FILES
int	put_files(t_line **head);
//REMOVE_EMPTY_DOUBLE_SINGLE_QUOTES
int remove_empty_double_and_single_quotes(t_line **head);
//VERIFIER COMMANDE
int verifier_commande(t_line **head, t_all *all);
//FILL_FLAG_AND_COMMANDE
//RENMOVE QUOTES FROM COMMANDE + FILL LES CHAR * FLAG ET COMMANDE
void	create_char_commande_node(t_line *node, t_line **head, t_all *all);
void  remove_quotes_from_commande(t_line **head);
void  fill_flag_and_commande(t_all *all, t_line **head);
//VERIFIER PIPE
int verifier_pipe(t_line **head);
//CREATE ARGC OF COMMANDE
int create_argc_of_command(t_line **head);
//REMPLIR ARGC OF COMMANDE NODE
int remplir_argc_of_command_node(t_line *node);
//EXPAND METTRE LES VARIABLES D ENVIRONEMENTS
int put_env_variables(t_line **head, t_all *all);
int	fill_expanded_str(char *expanded_str, char *str, t_all *all);
int count_taille_str_with_env(char *str, t_all *all);
int fount_index_of_env(char *env, t_all *all);
char  *take_name_of_env_from_str(char *str, int index);

//CREATE_SHELL_LIST 
t_shell_command **initialize_list_shell_command(t_line **head, int number_of_command);
//EXECUTION UTILS

int count_number_of_commands(t_line **head);

//STICK_STDIN_STDOUT
t_shell_command **stick_stdin_stdout(t_line **head, t_all *all);
//TOUT LES COLLAGE DE STDIN STDOUT
void	make_by_default(t_shell_command **head);
int	make_pipe(t_shell_command **shell_head);
int make_rederiction_stdin_stdout(t_shell_command **shell_head, t_line **line_head);
//REDERICTION
int make_redirect_append(t_shell_command *shell_node, t_line *line_node);
int	make_redirect_heredoc(t_shell_command *shell_node, t_line *line_node);
int	make_redirect_in(t_shell_command *shell_node, t_line *line_node);
int make_redirect_out(t_shell_command *shell_node, t_line *line_node);
int make_rederiction_stdin_stdout(t_shell_command **shell_head, t_line **line_head);


//DUP2
int	make_dup(t_shell_command *shell_node);

//EXTERN
int execution(t_line **line_head, t_shell_command **shell_head, t_all *all);
int execute_child_extern(t_shell_command *shell_node, t_all *all);
int make_extern_command(t_shell_command *shell_node, t_all *all);


//BUILD IN
int make_build_in_command(t_shell_command *shell_node, t_all *all);
//make echo
void make_build_in_echo(t_shell_command *shell_node);
//make cd
int	make_cd(t_shell_command *shell_node, t_all *all);
int	make_cd_home(t_shell_command *shell_head, t_all *all);
int	find_index_in_env(char **env, char *str);
char	*take_env_from_index(t_all *all, int	index);
int	add_pwd_oldpwd(char *old, char **env, int mode);
int	changes_pwd_oldpwd_values(t_all *all);
//MAKE PWD
int	make_pwd(t_shell_command *node);
//MAKE ENV
void  make_env(t_all *all, t_shell_command *shell_node);
int	add_to_env(t_shell_command *shell_node, t_all *all, char *valeur);
//EXPORT
int make_export(t_shell_command *shell_node, t_all *all);
void  printf_all_export(t_all *all);
int add_new_to_export(t_all *all, char *valeur);
int	add_to_env(t_shell_command *shell_node, t_all *all, char *valeur);
int	add_to_value_env(t_all *all, char *valeur);
char  **malloc_copy_env_export(char **env, char *valeur);
void	fill_copy_env(char **copy_env, char **env, char *valeur);

#endif