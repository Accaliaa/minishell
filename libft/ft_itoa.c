/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:26:34 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/14 02:20:10 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	static	cnt(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	cnv(int n, int i, char *c)
{
	if (n < 0)
	{
		c[0] = '-';
		n = -n;
	}
	while (n)
	{
		c[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*c;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = cnt(n);
	c = (char *)ft_calloc((i + 1), sizeof(char));
	if (!c)
		return (0);
	cnv(n, i, c);
	c[i] = '\0';
	return (c);
}
