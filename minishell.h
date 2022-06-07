#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <signal.h>


typedef struct s_all
{
    char **cmd;
    char **envp;
    t_list *lenvp;
    int hd;
   	int *inf;
    int *outf;
	char **delimiter;
    char *heredoc_line;
	int fd;
} t_all;

typedef struct s_p {
	char	**splitpaths;
	char	**args_hold;
	int	exit_value_hold;
}	t_pipe;

void	parse(char s);
int		handle_errors(char *argv);
int		handle_characters(char *s, int i);
int		handle_quotes(char *s);
int		ft_cmp(char *s, char c);
int 	check_quote(char *str);
void 	converter(char **envp,t_all *all);
t_all 	*ft_init(t_all *all);
int		check_redirections(t_list *list);
void	ft_exec (t_list *l, char **env);
void	multiprocessing(t_list *l, char **envp);
void	check_outfiles(t_list *list);
void	check_heredoc(t_list *l);
int		ft_strcmp(const char *s1, const char *s2);
int		*sttc_var(void);
int	check_dollar(t_list *l);
#endif