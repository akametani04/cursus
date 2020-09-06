/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:40:51 by akametan          #+#    #+#             */
/*   Updated: 2020/07/12 20:40:53 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_null_len;
	char	*ptr;

	s1_null_len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(sizeof(char) * s1_null_len);
	if (ptr)
	{
		ft_memcpy(ptr, s1, s1_null_len);
	}
	return (ptr);
}
