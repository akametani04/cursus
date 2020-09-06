/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:05:38 by akametan          #+#    #+#             */
/*   Updated: 2020/08/28 22:20:34 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_p(void *ph, t_spec *spec, int *len)
{
	int num_len;
	int output_len;
	int prec_len;

	num_len = hex_count((long long unsigned)ph);
	if (spec->dot && spec->precision <= 0)
		num_len = 0;
	if (spec->precision != -1 && spec->flag == '0')
		spec->flag = '\0';
	output_spec(&num_len, &output_len, &prec_len, spec);
	if (output_len == spec->width && spec->flag == '\0')
		put_char(' ', spec->width - (prec_len + num_len + 2), len);
	*len += write(1, "0x", 2);
	put_char('0', prec_len, len);
	if (spec->dot && spec->precision <= 0)
		;
	else if ((long long unsigned)ph == 0 && num_len == 1)
		*len += write(1, "0", 1);
	else
		num_output((long long unsigned)ph, len, "0123456789abcdef", 16);
	if (output_len == spec->width && spec->flag == '0')
		put_char('0', spec->width - (prec_len + num_len + 2), len);
	if (output_len == spec->width && spec->flag == '-')
		put_char(' ', spec->width - (prec_len + num_len + 2), len);
}

void	output_u(unsigned int ui_num, t_spec *spec, int *len)
{
	int num_len;
	int output_len;
	int prec_len;

	num_len = ui_count(ui_num);
	if (spec->dot && spec->precision <= 0 && ui_num == 0)
		num_len = 0;
	if (spec->precision != -1 && spec->flag == '0')
		spec->flag = '\0';
	output_spec(&num_len, &output_len, &prec_len, spec);
	if (output_len == spec->width && spec->flag == '\0')
		put_char(' ', spec->width - (prec_len + num_len), len);
	if (output_len == spec->width && spec->flag == '0')
		put_char('0', spec->width - (prec_len + num_len), len);
	put_char('0', prec_len, len);
	if ((long long unsigned)ui_num == 0 && num_len != 0)
		*len += write(1, "0", 1);
	else
		num_output((long long unsigned)ui_num, len, "0123456789", 10);
	if (output_len == spec->width && spec->flag == '-')
		put_char(' ', spec->width - (prec_len + num_len), len);
}

void	output_x(unsigned int ui_num, t_spec *spec, int *len)
{
	int num_len;
	int output_len;
	int prec_len;

	num_len = hex_count((long long unsigned)ui_num);
	if (spec->dot && spec->precision <= 0 && ui_num == 0)
		num_len = 0;
	if (spec->precision != -1 && spec->flag == '0')
		spec->flag = '\0';
	output_spec(&num_len, &output_len, &prec_len, spec);
	if (output_len == spec->width && spec->flag == '\0')
		put_char(' ', spec->width - (prec_len + num_len), len);
	if (output_len == spec->width && spec->flag == '0')
		put_char('0', spec->width - (prec_len + num_len), len);
	put_char('0', prec_len, len);
	if ((long long unsigned)ui_num == 0 && num_len != 0)
		*len += write(1, "0", 1);
	else if (num_len != 0 && spec->type == 'x')
		num_output((long long unsigned)ui_num, len, "0123456789abcdef", 16);
	else if (num_len != 0 && spec->type == 'X')
		num_output((long long unsigned)ui_num, len, "0123456789ABCDEF", 16);
	if (output_len == spec->width && spec->flag == '-')
		put_char(' ', spec->width - (prec_len + num_len), len);
}
