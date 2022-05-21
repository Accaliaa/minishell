/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:41:27 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/20 16:19:04 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int static	ft_len(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

void static	ft_cpy(const char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(const char *src)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_len(src) + 1));
	if (!p)
		return (0);
	ft_cpy(src, p);
	return (p);
}
