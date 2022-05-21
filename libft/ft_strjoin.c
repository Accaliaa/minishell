/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:34:12 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/20 16:35:01 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ftcnt(const char *s1, const char *s2, char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		c[i] = s2[j];
		i++;
		j++;
	}
	c[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	ftcnt(s1, s2, c);
	return (c);
}
