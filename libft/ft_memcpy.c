/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:37:46 by akametan          #+#    #+#             */
/*   Updated: 2020/07/12 20:37:51 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	size_t i;

	i = 0;
	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	while (i < n)
	{
		*((char *)buf1 + i) = *((char *)buf2 + i);
		i++;
	}
	return (buf1);
}
