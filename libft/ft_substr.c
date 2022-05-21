/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:33:11 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/20 14:33:13 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (!s)
		return (0);
	if (!len)
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen((char *)s))
		len = (size_t)ft_strlen((char *)s);
	if ((unsigned long)start > ft_strlen((char *)s))
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i + start <= start + len - 1)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
