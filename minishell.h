/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:46:58 by zdasser           #+#    #+#             */
/*   Updated: 2022/05/21 14:53:18 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <readline/readline.h>
#include "libft/libft.h"

typedef struct s_all
{
    char **cmd;
    char **envp;
    t_list *lenvp;
    int hd;
    char *inf;
    char *outf;
} t_all;

void parse(char s);
int	handle_errors(char *argv);
int handle_characters(char *s, int i);
int	handle_quotes(char *s);
int	ft_cmp(char *s, char c);
#endif