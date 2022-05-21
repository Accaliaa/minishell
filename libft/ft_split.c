/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 03:29:55 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/20 15:54:08 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

int	static	end(const char *s, char c)
{
	int	k;

	k = 0;
	while (s[k] != c && s[k])
		k++;
	return (k);
}

int	static	fill(char **p, char const *s, char c)
{
	int	i;
	int	n;
	int	k;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			k = end(&s[i], c);
			p[n] = ft_substr(s, i, k);
			if (!p[n])
			{
				while (n--)
					free(p[n]);
				return (0);
			}
			n++;
			i += k;
		}
		else if (s[i] && s[i] == c)
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		filled;
	char	**p;

	if (!s)
		return (NULL);
	j = count(s, c);
	p = (char **)malloc(sizeof(char *) * (j + 1));
	if (!p)
		return (NULL);
	filled = fill(p, s, c);
	if (!filled)
	{
		free(p);
		return (NULL);
	}
	p[j] = NULL;
	return (p);
}
