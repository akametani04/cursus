/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:29:08 by akametan          #+#    #+#             */
/*   Updated: 2020/07/12 21:13:22 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}
