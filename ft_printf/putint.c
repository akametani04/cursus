/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:57:13 by akametan          #+#    #+#             */
/*   Updated: 2020/08/27 13:33:44 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putint_num(long long i_num, int num_len, int *len)
{
	if (i_num < 0)
	{
		*len += write(1, "-", 1);
		i_num *= -1;
	}
	if (num_len == 0)
		;
	else if (i_num == 0)
		*len += write(1, "0", 1);
	else
		integer_output(i_num, len);
}

void	putint_precision(long long i_num, int output_len, int num_len, int *len)
{
	int i;

	i = 0;
	if (i_num < 0)
	{
		*len += write(1, "-", 1);
		i_num *= -1;
	}
	while (i++ < output_len - num_len)
		*len += write(1, "0", 1);
	if (i_num == 0 && num_len != 0)
		*len += write(1, "0", 1);
	else
		integer_output(i_num, len);
}

void	putint_zero(long long i_num, t_spec *spec, int *len, int num_len)
{
	int total;

	total = 0;
	if (i_num < 0)
	{
		*len += write(1, "-", 1);
		i_num *= -1;
		total++;
	}
	while (total++ < spec->width - num_len)
		*len += write(1, "0", 1);
	if (i_num == 0 && num_len != 0)
		*len += write(1, "0", 1);
	else
		integer_output(i_num, len);
}

void	putint_left(long long i_num, t_spec *spec, int *len, int num_len)
{
	int i;

	i = 0;
	if (i_num < 0)
	{
		*len += write(1, "-", 1);
		i_num *= -1;
		i++;
	}
	while (0 < spec->precision - num_len)
	{
		*len += write(1, "0", 1);
		spec->precision--;
		i++;
	}
	if (i_num == 0 && num_len != 0)
		*len += write(1, "0", 1);
	else
		integer_output(i_num, len);
	while (i++ < spec->width - num_len)
		*len += write(1, " ", 1);
}

void	putint_noflag(long long i_num, t_spec *spec, int *len, int num_len)
{
	int		total;
	int		zero_num_len;

	total = 0;
	zero_num_len = num_len < spec->precision ? spec->precision : num_len;
	if (i_num < 0)
		zero_num_len++;
	put_char(' ', spec->width - zero_num_len, len);
	if (i_num < 0)
	{
		*len += write(1, "-", 1);
		i_num *= -1;
		total++;
	}
	put_char('0', spec->precision - num_len, len);
	if (i_num == 0 && num_len != 0)
		*len += write(1, "0", 1);
	else
		integer_output(i_num, len);
}
