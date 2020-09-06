/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:17:59 by akametan          #+#    #+#             */
/*   Updated: 2020/08/27 17:56:23 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_c(int c, t_spec *spec, int *len)
{
	if (spec->flag == '\0' && -1 < spec->width)
		put_char(' ', spec->width - 1, len);
	else if (spec->flag == '0' && -1 < spec->width)
		put_char('0', spec->width - 1, len);
	*len += write(1, &c, 1);
	if (spec->flag == '-' && -1 < spec->width)
		put_char(' ', spec->width - 1, len);
}

void	output_s(const char *str, t_spec *spec, int *len)
{
	int slen;
	int i;

	i = 0;
	if (spec->width != -1 && spec->dot && spec->precision <= 0)
		put_char(' ', spec->width, len);
	if (spec->dot && spec->precision <= 0)
		return ;
	else
		slen = ft_strlen(str);
	if (spec->precision != -1)
		slen = (spec->precision < slen) ? spec->precision : slen;
	if (spec->flag != '-' && slen < spec->width)
	{
		if (spec->flag == '0')
			put_char('0', spec->width - slen, len);
		else
			put_char(' ', spec->width - slen, len);
	}
	if (!str)
		*len += write(1, "(null)", slen);
	else
		*len += write(1, str, slen);
	if (spec->flag == '-' && slen < spec->width)
		put_char(' ', spec->width - slen, len);
}

void	output_per(t_spec *spec, int *len)
{
	int i;

	i = 0;
	if (spec->flag == '0')
	{
		while (i++ < spec->width - 1)
			*len += write(1, "0", 1);
	}
	else if (spec->flag == '\0')
	{
		while (i++ < spec->width - 1)
			*len += write(1, " ", 1);
	}
	*len += write(1, "%%", 1);
	if (spec->flag == '-')
	{
		while (i++ < spec->width - 1)
			*len += write(1, " ", 1);
	}
}

void	output_expect(t_spec *spec, int *len)
{
	if (spec->flag == '0')
	{
		while (1 < spec->width--)
			*len += write(1, "0", 1);
	}
	else if (spec->flag == '\0')
	{
		while (1 < spec->width--)
			*len += write(1, " ", 1);
	}
}
