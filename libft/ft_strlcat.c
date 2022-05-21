/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:38:05 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/20 16:39:18 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	l = ft_strlen(dst);
	i = 0;
	if (l >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[i] && l + i < dstsize - 1)
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = 0;
	return (l + ft_strlen(src));
}
