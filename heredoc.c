/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:04:34 by zdasser           #+#    #+#             */
/*   Updated: 2022/06/13 20:25:37 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_delimiter(t_list *l, char *s, int *count)
{
	int	i;
	int j;
	char *delimiter;
	
	i = 0;
	j = 0;
	while (s[i] && i + 1 <= (int)ft_strlen(s))
	{
		if (s[i] == '<' && s[i + 1] == '<' && ft_strlen(s) > 2)
		{
		
			j = i + 2;
			while (s[j] != 32 && s[j] != '\n' && s[j] != '<' && s[j] && s[j] != '>')
				j++;
			delimiter = ft_substr(s, i + 2, j);
			printf("size linked list : %i\n", ft_lstsize(l));
			printf("count : %s\n", delimiter);
			((t_all *)(l->content))->delimiter[*count] = delimiter;
			printf("after\n");
		    *count+= 1;
		}
		if (j)
			i += j - 1;
		i++;
		if (i > (int)ft_strlen(s))
			i = ft_strlen(s);
	}
}

void cmd_loop(t_list *l)
{
	char **s;
	int	i;
	int j;
	int count;
	char *delimiter;
	while (l)
	{
		count = 0;
		printf(".....%i,,,,\n", ((t_all *)l->content)->hd);
		((t_all *)l->content)->delimiter = malloc(sizeof(char *) * ((t_all *)l->content)->hd + 1);
		i = 0;
		j = 0;
		s = ((t_all *)l->content)->cmd;
		while (s && s[i])
		{
			if (ft_cmp(s[i], '<'))
			{
				if ( ft_strlen(s[i]) == 2 && s[i][j] == '<' && s[i][j + 1] == '<')
				{
					delimiter = s[i + 1];
					((t_all *)l->content)->delimiter[count] = delimiter;
				}
				else
					get_delimiter(l, s[i], &count);
			}
			i++;
			j++;
		}
		l = l->next;
    }
}

void	check_heredoc(t_list *l)
{
	int i;
	int j;
	int	n;
	char *tmp;
	char **line;
	char *input = NULL;
	int fd;

	fd = 0;
    cmd_loop(l);
	n = 0;
	while (l)
	{
		if (n > 0)
			close(((t_all *)(l->prev->content))->fd);
		fd = 0;
		i = 0;
		j = ((t_all *)l->content)->hd;
		((t_all *)(l->content))->heredoc_line = "";
		line = &(((t_all *)(l->content))->heredoc_line);
		if (j)
		{
			while (i < j)
			{
				input = readline("heredoc>");
				while (!ft_strcmp(input, ((t_all *)l->content)->delimiter[i]))
				{
				    tmp = ft_strjoin(input, "/");
					*line = ft_strjoin(*line, tmp);
					input = readline("heredoc>");
					free(tmp);
				}
				i++;
			}
		}
		((t_all *)l->content)->fd = open("temp", O_CREAT | O_RDWR | O_APPEND, 0755);
		fd = ((t_all *)l->content)->fd;
		if (fd > 2)
			ft_putstr_fd(*line, ((t_all *)l->content)->fd);
		n++;
		l = l->next;
		
	}
}
