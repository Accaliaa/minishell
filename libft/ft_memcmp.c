/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:16:01 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/14 02:37:08 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*t2;

	t = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (i < n && t2[i] == t[i])
		i++;
	if (i != n)
		return (t[i] - t2[i]);
	return (0);
}
