#ifndef HEAD_H
# define HEAD_H
//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt

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

#define	HOME_VALUE	"HOME=/home/fepopadi"
#define PATH_VALUE	"PATH=/home/fepopadi/bin:/home/fepopadi/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
#define PWD_VALUE		"PWD=/home/fepopadi/Desktop/Minishell"
#define	USER_VALUE	"USER=fepopadi"
#define	SHLVL_VALUE	"SHLVL=1"

typedef enum token_type //le type de chaque charactere qu on regarde
{
  TOKEN_SINGLE_QUOTES, //' '
  TOKEN_DOUBLE_QUOTES, // ""
  TOKEN_PIPE, // |
  TOKEN_REDIRECT_IN, // <
  TOKEN_REDIRECT_OUT, // >
  TOKEN_APPEND, // >>
  TOKEN_HEREDOC, // <<
  TOKEN_COMMANDE, // commande
} e_token_type;

typedef enum quotes // pour savoir si le charactere qu on regarde si il est dans des double single ou pas de quotes
{
  DOUBLE_QUOTES,
  SINGLE_QUOTES,
  NONE,
} e_quotes;

typedef struct t_line
{
  struct t_line *next;
  struct t_line *prev;
  char *valeur;
  e_token_type type;
  e_quotes quotes;
} t_line;

typedef struct t_all
{
  int start; // index pour les double quotes ou ils commencent et ou ils finissent le int end aussi
  int end;
  int commande; //sera a 1 si on a une commande donc on cerche un argument ou redericition 0 si on a pas de commande avant
  char *line;
  char **path;
  char **env;
} t_all;

//MAIN
int	main(int argc, char **argv, char **env);
void	free_all(t_all *all);
void	free_list(t_line **head);

//UTILS
int	ft_strlen(char *str);
void	ft_strcpy(char *str, char *dest);
t_all	*malloc_struct_all(void);
int	ft_strncmp(char *avec_quoi, char *comparer, int nbr);
void	ft_strncpy(char *str, char *dest, int index, int taille);

//env_all/COPY_ENV_OF_ALL
void	copy_env_in_all(t_all *all, char **env);

//env_all/CREATE ENV FOR ALL
void  create_env_in_all(t_all *all);

// PATH
void  copy_path(t_all *all);

// SIGNAL
void  make_signal(void);

//PARSING
void  parsing(t_all *all, t_line **head);

//ADD COMMANDE
void	add_commande(int *index, t_all *all, t_line **head);

#endif