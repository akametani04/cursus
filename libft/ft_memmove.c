/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:38:15 by akametan          #+#    #+#             */
/*   Updated: 2020/07/15 23:34:08 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	void *dest;

	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	dest = buf1;
	if (buf1 < buf2)
	{
		while (0 < n)
		{
			*((char *)buf1++) = *((char *)buf2++);
			n--;
		}
	}
	else
	{
		buf1 += n - 1;
		buf2 += n - 1;
		while (0 < n)
		{
			*((char *)buf1--) = *((char *)buf2--);
			n--;
		}
	}
	return (dest);
}
