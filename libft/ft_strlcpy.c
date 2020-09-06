/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:41:34 by akametan          #+#    #+#             */
/*   Updated: 2020/07/12 20:41:36 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
	{
		ft_memcpy(dest, src, src_len + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		*(dest + size - 1) = '\0';
	}
	return (src_len);
}
