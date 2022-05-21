/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:18:11 by zdasser           #+#    #+#             */
/*   Updated: 2021/11/11 21:23:06 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
