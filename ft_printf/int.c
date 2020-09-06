/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:30:07 by akametan          #+#    #+#             */
/*   Updated: 2020/08/27 13:43:21 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_i_d(long long i_num, t_spec *spec, int *len)
{
	int num_len;
	int output_len;
	int prec_len;

	num_len = len_count(i_num);
	if (spec->dot && spec->precision <= 0 && i_num == 0)
		num_len = 0;
	output_spec(&num_len, &output_len, &prec_len, spec);
	if (output_len == num_len)
		putint_num(i_num, num_len, len);
	else if (output_len == spec->precision)
		putint_precision(i_num, output_len, num_len, len);
	else if (output_len == spec->width)
	{
		if (spec->flag == '0' && spec->precision != -1)
			spec->flag = '\0';
		if (spec->flag == '0')
			putint_zero(i_num, spec, len, num_len);
		else if (spec->flag == '-')
			putint_left(i_num, spec, len, num_len);
		else
			putint_noflag(i_num, spec, len, num_len);
	}
}

void	output_spec(int *num_len, int *output_len, int *prec_len, t_spec *spec)
{
	*output_len = *num_len;
	if (*output_len < spec->precision)
		*output_len = spec->precision;
	if (*output_len < spec->width)
		*output_len = spec->width;
	if (*num_len < spec->precision)
		*prec_len = spec->precision - *num_len;
	else
		*prec_len = 0;
}
