/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadi <skadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:41:39 by skadi             #+#    #+#             */
/*   Updated: 2022/06/18 12:20:07 by skadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_export(t_list *l)
{
    int i;
    char *s;
    while(l)
    {
        s = ((t_all *)(l->content))->ccmd;
        w
        
        
        l = l->next;
    }
}

void get_var_value(char *s)
{
    t_var data;
    int i;

    i = 0;
    while(s[i] != '=')
        i++;
    data->name = ft_substr(s, 0, i - 1);
    data->content = ft_substr(s, i + 1, ft_strlen(s));   
    
}

int calculate_size(char **s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return(i);
}

int var_dec(t_list *l)
{
    char **s;
    int i;

    i = 0;
    if(ft_lstsize_bonus(l) == 1)
    {
        
        s = ((t_all *)(l->content))->ccmd;
        if(calculate_size(s) != 1)
            return(0);
        else if (calculate_size == 1)
        {
            if(ft_strcmp(s[0], "="))
                get_var_value(s[0]);
        }
    }
    ft_export(l);
}





