/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:41:21 by akametan          #+#    #+#             */
/*   Updated: 2020/08/27 17:45:58 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_spec(t_spec *spec)
{
	spec->flag = '\0';
	spec->width = -1;
	spec->precision = -1;
	spec->type = '\0';
	spec->dot = false;
}

void	flag_itoa(char c, t_spec *spec, va_list ap, int *val)
{
	if (*val != -1 && c == '-')
		*val = 0;
	else if (c == '*')
	{
		*val = va_arg(ap, int);
		if (spec->dot && *val < 0)
		{
			spec->dot = false;
			*val = -1;
		}
		else if (!spec->dot && *val < 0)
		{
			spec->flag = '-';
			*val *= -1;
		}
	}
	else if (*val == -1 && c != '-')
		*val = c - '0';
	else if (*val != -1)
	{
		*val *= 10;
		*val += c - '0';
	}
}

void	dec_spec(char **str, t_spec *spec, va_list ap)
{
	while (**str == '-' || **str == '0')
	{
		if (spec->flag == '-')
			;
		else
			spec->flag = **str;
		(*str)++;
	}
	while (ft_isdigit(**str) || **str == '.' || **str == '*')
	{
		if (**str == '.' && !spec->dot)
			spec->dot = true;
		else if (**str == '.' && spec->dot)
			spec->precision = -1;
		if ((ft_isdigit(**str) || **str == '*') && !(spec->dot))
			flag_itoa(**str, spec, ap, &spec->width);
		else if ((ft_isdigit(**str) || **str == '*') && spec->dot)
			flag_itoa(**str, spec, ap, &spec->precision);
		(*str)++;
	}
	if (istype(**str))
	{
		spec->type = **str;
		(*str)++;
	}
}

void	func_switch(t_spec *spec, va_list ap, int *len)
{
	if (spec->type == 'c')
		output_c(va_arg(ap, int), spec, len);
	else if (spec->type == 's')
		output_s(va_arg(ap, const char *), spec, len);
	else if (spec->type == 'p')
		output_p(va_arg(ap, void *), spec, len);
	else if (spec->type == 'd' || spec->type == 'i')
		flag_i_d(va_arg(ap, int), spec, len);
	else if (spec->type == '%')
		output_per(spec, len);
	else if (spec->type == 'u')
		output_u(va_arg(ap, unsigned int), spec, len);
	else if (spec->type == 'x' || spec->type == 'X')
		output_x(va_arg(ap, unsigned int), spec, len);
	else
		output_expect(spec, len);
}
