/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:08:28 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/20 16:24:22 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp = tmp->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}
