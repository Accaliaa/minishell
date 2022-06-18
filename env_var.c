/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadi <skadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:19:51 by skadi             #+#    #+#             */
/*   Updated: 2022/06/17 15:14:20 by skadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_var(t_list *lenvp, char **var)
{
    char *content;
    char *tmp;

    while(lenvp)
    {
        content = ((char *)(lenvp->content));
        if (!ft_strncmp(content, *var + 1, ft_strlen(*var) - 1))
        {
            tmp = *var;
            *var = content + ft_strlen(*var);
            free(tmp);
        }
        lenvp = lenvp->next;
    }
}

void check_var(t_list *l)
{
    char    **s;
    int     i;

    while(l)
    {
        i = 0;
        s = ((t_all *)(l->content))->ccmd;
        while(s[i])
        {
            if(!ft_strcmp(s[i], "$"))
                get_var(((t_all *)(l->content))->lenvp, &s[i]);
            i++;
        }
        l = l->next;
    }
}