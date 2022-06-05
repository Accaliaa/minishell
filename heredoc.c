/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:04:34 by zdasser           #+#    #+#             */
/*   Updated: 2022/06/04 17:42:51 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void get_delimiter(t_list *l, char *s, int *count)
{
	int	i;
	int j;
	char *delimiter;
	
	i = 0;
	while (s[i] && i + 1 <= (int)ft_strlen(s))
	{
		if (s[i] == '<' && s[i + 1] == '<' && ft_strlen(s) > 2 )
		{
			j = i + 2;
			while(s[j] != 32 && s[j] != '\n' && s[j] != '<' && s[j] && s[j] != '>')
				j++;
			delimiter = ft_substr(s, i + 2, j);
			((t_all *)l->content)->delimiter[*count] = delimiter;
		}
		else if( ft_strlen(s) == 2 && s[i] == '<' && s[i + 1] == '<')
		{
			delimiter = s + 1;
			((t_all *)l->content)->delimiter[*count] = delimiter;
		}
		*count+= 1;
		if(j)
			i += j - 1;
		i++;
		if(i > (int)ft_strlen(s))
			i = ft_strlen(s);
	}
}



void cmd_loop(t_list *l)
{
	char **s;
	int	i;
	int count;

	count = 0;
	while(l)
	{
		((t_all *)l->content)->delimiter = malloc(sizeof(char *) * ((t_all *)l->content)->hd + 1);
		i = 0;
		s = ((t_all *)l->content)->cmd;
		while(s[i])
		{
			if (ft_cmp(s[i], '<'))
				get_delimiter(l, s[i], &count);
			i++;
		}
		l = l->next;
    }
}

void	check_heredoc(t_list *l)
{
	int i;
	int j;
	char *line = "/";
	char *tmp;
	char *input = NULL;

    cmd_loop(l);
	while(l)
	{
		i = 0;
		j = ((t_all *)l->content)->hd;
		printf("number of heredoc : %i \n", j);
		if(j)
		{
			while(i < j)
			{
				input = readline("heredoc>");
				printf("delimiter : %s \n", ((t_all *)l->content)->delimiter[i]);
				while(!ft_strcmp(input, ((t_all *)l->content)->delimiter[i]))
				{
					printf("here\n");
				    tmp = ft_strjoin(input, "/");
					line = ft_strjoin(line, tmp);
					input = readline("heredoc>");
					printf("______%s____\n", line);
					free(tmp);
				}
				i++;
			}
		}
		l = l->next;
	}
}