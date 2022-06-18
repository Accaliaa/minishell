/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:19:51 by skadi             #+#    #+#             */
/*   Updated: 2022/06/18 12:41:47 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_var(t_list *lenvp, char **var)
{
    char *content;

    while(lenvp)
    {
        content = ((char *)(lenvp->content));
        if (!ft_strncmp(content, *var + 1, ft_strlen(*var) - 1))
            *var = content + ft_strlen(*var);
        lenvp = lenvp->next;
    }
}

void check_var(t_list *l)
{
    char    **s;
    int     i;
	char	*tmp;

    while(l)
    {
        i = 0;
        s = ((t_all *)(l->content))->ccmd;
        while(s[i])
        {
            if(ft_cmp(s[i], '$'))
			{
				tmp = s[i];
				get_var(((t_all *)(l->content))->lenvp, &s[i]);
				free(tmp);
				printf("here\n");
			}
            i++;
        }
        l = l->next;
    }
}