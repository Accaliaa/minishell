/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:57:59 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/14 05:43:33 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	if (!dst && !src)
		return (0);
	cdst = (char *)dst;
	csrc = (char *)src;
	if (src > dst)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	else
	{
		while (len--)
			*(cdst + len) = *(csrc + len);
	}
	return (dst);
}
