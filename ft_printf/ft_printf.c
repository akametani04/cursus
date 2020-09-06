/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:12:43 by akametan          #+#    #+#             */
/*   Updated: 2020/08/28 22:12:45 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_spec	spec;
	int		len;
	char	*str;

	if (!fmt)
		return (-1);
	len = 0;
	str = (char *)fmt;
	va_start(ap, fmt);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			init_spec(&spec);
			dec_spec(&str, &spec, ap);
			func_switch(&spec, ap, &len);
		}
		else
			len += write(1, str++, 1);
	}
	va_end(ap);
	return (len);
}
