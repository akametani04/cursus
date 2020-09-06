/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:40:40 by akametan          #+#    #+#             */
/*   Updated: 2020/07/13 22:42:11 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int s_len;

	s_len = ft_strlen(s);
	while (0 <= s_len)
	{
		if (*s == c)
			return (char *)s;
		s_len--;
		s++;
	}
	return (NULL);
}
