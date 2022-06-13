/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:43:36 by zdasser           #+#    #+#             */
/*   Updated: 2022/06/13 21:36:01 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"minishell.h"


int	ft_count_infiles(char **s)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;

	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '<' && s[i][j + 1] == '<')
				j += 2;
			if (s[i][j] == '<' && s[i][j + 1] != '<')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	handle_multi_infiles(char *s, t_list *list, int *count)
{
	char *infile;
	int j;
	int i;


	i = 0;
	j = 0;
	
	printf("hellooooo\n");
	while (s[j] && j + 1 <= (int)ft_strlen(s))
	{
		if (s[j] == '<' && s[j + 1] == '<')
		{
			((t_all *)list->content)->hd++;
			j += 2;
		}
		else if (s[j] == '<' && s[j + 1] != '<' )
		{
			i = j + 1;
			while (s[i] != 32 && s[i] != '\n' && s[i] != '<' && s[i])
				i++;
			infile = ft_substr(s, j + 1, i - 1);
			((t_all *)list->content)->inf[*count] = open(infile, O_RDONLY);
			*count += 1;
		} 
		if (i)
			j += i - 1;
		j++;
		if (j > (int)ft_strlen(s))
			j = ft_strlen(s);
	}
	
		
}

void	check_redirections(t_list *list)
{
	int i;
	char **s;
	char *infile;
	int count;
	int redir;

	while (list)
	{
		i = 0;
		redir = 0;
		s = ((t_all *)list->content)->cmd;
		((t_all *)list->content)->hd = 0;
		((t_all *)list->content)->n_inf = 0;
		count = ft_count_infiles(s);
		if (count)
		{
			((t_all *)list->content)->inf = malloc(sizeof(int) * count);
			((t_all *)list->content)->n_inf = count;
		}
		else
			((t_all *)list->content)->inf = (int *)ft_calloc(1, sizeof(int));

		while (s[i])
		{	printf("hellllo\n");
			if (ft_cmp(s[i], '<') && ft_strlen(s[i]) == 1)
			{
				infile = s[i + 1];
				((t_all *)list->content)->inf[redir] = open(infile, O_RDONLY);
				i++;
				redir++;

			}
			else if (ft_strlen(s[i]) > 1 && ft_cmp(s[i], '<'))
				handle_multi_infiles(s[i], list, &redir);
			i++;
		}
		list = list->next;
	}
}