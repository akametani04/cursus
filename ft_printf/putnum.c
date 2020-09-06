/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:24:35 by akametan          #+#    #+#             */
/*   Updated: 2020/08/26 11:36:21 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ui_count(long long unsigned n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (0 < n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int		len_count(long long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (0 < n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int		hex_count(long long unsigned n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (0 < n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

void	integer_output(long long i_num, int *len)
{
	char c;

	if (i_num == 0)
		return ;
	c = (i_num % 10) + '0';
	integer_output(i_num / 10, len);
	*len += write(1, &c, 1);
}

void	num_output(long long unsigned ui_num, int *len, char *num, int base)
{
	char c;

	if (ui_num == 0)
		return ;
	c = num[ui_num % base];
	num_output(ui_num / base, len, num, base);
	*len += write(1, &c, 1);
}
