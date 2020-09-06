/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 01:23:06 by akametan          #+#    #+#             */
/*   Updated: 2020/08/27 13:40:01 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
	c == '%' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

int		ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (6);
	while (str[i])
		i++;
	return (i);
}

void	put_char(char c, int n, int *len)
{
	int i;

	i = 0;
	while (i < n)
	{
		*len += write(1, &c, 1);
		i++;
	}
}
