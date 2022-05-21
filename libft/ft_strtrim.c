/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 03:41:06 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/12 22:50:25 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int static	cmp(const char *set, char s1)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char static	*p(const char *s1, int start, int i)
{
	if (start <= i)
		return (ft_substr(s1, start, i - start + 1));
	else
		return (ft_strdup(""));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i])
	{
		if (!cmp(set, s1[i]))
			break ;
		i++;
	}
	start = i;
	i = ft_strlen(s1) - 1;
	while (i >= start)
	{
		if (!cmp(set, s1[i]))
			break ;
		i--;
	}
	return (p(s1, start, i));
}
